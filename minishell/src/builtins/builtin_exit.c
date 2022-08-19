/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:17:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 22:51:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MSH_EXIT "msh: exit: "
#define EXIT_NARG_STR "too many arguments" 			//* 1
#define EXIT_IARG_STR ": numeric argument required"	//* 2
#define EXIT_WR_ERR "msh: exit: write error"
#define EXIT_NARG 1
#define EXIT_IARG 2

/*
	MAX 9223372036854775808		LLONG_MAX
	MIN -9223372036854775809	LLONG_MIN
*/

static void	destroy_msh(t_cmd *cmd, int exitcode)
{
	btree_destroy(cmd->tree);
	env_destroy(cmd->env);
	cmd_destructor(cmd->croot);
	rl_clear_history();
	exit(exitcode);
}

static int	isneg(char *str)
{
	while (*str)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

static char	*trim_value(char *str, int *exitcode)
{
	char	*begin;
	size_t	len;

	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
		str++;
	while (*str == '0' && ft_isdigit(*str + 1))
		str++;
	len = 1;
	begin = str;
	while (ft_isdigit(*str))
	{
		str++;
		len++;
	}
	if (len < 1 || len > 19)
		return (*exitcode = 2, NULL);
	while (ft_isspace(*str))
		str++;
	if (*str)
		return (*exitcode = 2, NULL);
	return (ft_strldup(begin, len));
}

static int	get_exitcode(char *str, int *exitcode)
{
	char	*value;
	t_ull	nb;
	int		error;

	error = 0;
	value = trim_value(str, &error);
	if (error)
		return (EXIT_IARG);
	if (!value)
		return (ERR_MALLOC);
	nb = ft_atoull(value);
	free(value);
	if (nb > LLONG_MAX || (isneg(str) && nb + 1 > LLONG_MAX))
		return (EXIT_IARG);
	*exitcode = nb % 256;
	if (isneg(str))
		*exitcode = 256 - *exitcode;
	return (SUCCESS);
}

int	builtin_exit(int ac, char **argv, t_env *env, t_cmd *cmd)
{
	int		exitcode;
	int		error;

	res_i_o(cmd);
	sc_write(2, "exit\n", EXIT_WR_ERR);
	if (ac == 1)
	{
		exitcode = env_old_exitcode(env);
		destroy_msh(cmd, exitcode);
	}
	error = get_exitcode(argv[1], &exitcode);
	if (error == EXIT_IARG)
	{
		if (err_msg_3(MSH_EXIT, argv[1], EXIT_IARG_STR))
			destroy_msh(cmd, 255);
		destroy_msh(cmd, EXIT_IARG);
	}
	if (ac > 2)
	{
		if (err_msg_2(MSH_EXIT, EXIT_NARG_STR))
			return (-1);
		return (EXIT_NARG);
	}
	destroy_msh(cmd, exitcode);
	return (1);
}
/*
int	main(int ac, char **av, char **envp)
{
	int		exitcode;
	t_env	*env;

	exitcode = 0;
	env = env_init(envp);
	if (env)
	{
		exitcode = builtin_exit(ac, av, env);
		env_destroy(&env);
		ft_dprintf(2, "exitcode: [%d]\n", exitcode);
	}
	return (exitcode);
}
*/

/*

EXIT MODULO 256

exit without n => last exitcode value

exit with n => n

bash: exit: d : argument numérique nécessaire => 2

bash: exit: trop d'arguments => 1 *NO EXIT*

*/
