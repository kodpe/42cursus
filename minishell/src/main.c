/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:50:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 22:27:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CONTINUE 1
#define BREAK 2

int	g_g;

int	routine_2(int *exitcode, t_btree **tree, t_env **env)
{
	int		ctrld;
	char	*input;

	ctrld = 0;
	g_g = 0;
	if (env_update_exitcode(*env, *exitcode))
		return (BREAK);
	input = get_line_input(&ctrld);
	if (env_update_exitcode(*env, *exitcode))
		return (BREAK);
	if (ctrld)
		return (BREAK);
	if (!input)
		return (CONTINUE);
	*tree = parser(lexer(input), exitcode);
	if (*exitcode == ERR_MALLOC)
		return (BREAK);
	if (!*tree)
		return (CONTINUE);
	return (0);
}

int	routine(t_env *env)
{
	t_btree	*tree;
	int		exitcode;
	int		ret;

	tree = NULL;
	exitcode = 0;
	while (1)
	{
		ret = routine_2(&exitcode, &tree, &env);
		if (ret == 2)
			break ;
		else if (ret == 1)
			continue ;
		exitcode = pre_exec(tree, &env, &tree);
		if (exitcode == -1)
			break ;
		btree_destroy(&tree);
	}
	btree_destroy(&tree);
	env_destroy(&env);
	rl_clear_history();
	return (exitcode);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = env_init(envp);
	if (!env)
		return (ERR_MALLOC);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);
	return (routine(env));
	(void)av;
	(void)ac;
}
