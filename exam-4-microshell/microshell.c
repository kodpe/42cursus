#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	k;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = 0;
	return (str);
}

char	*ft_strjointri(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*complete;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	complete = ft_strjoin(tmp, s3);
	free(tmp);
	tmp = NULL;
	return (complete);
}

int		is_pipe(char *str)
{
	if (str == NULL)
		return 0;
	return strcmp(str, "|") ? 0 : 1;
}

int		is_semicolon(char *str)
{
	if (str == NULL)
		return 0;
	return strcmp(str, ";") ? 0 : 1;
}

int		is_separator(char *str)
{
	return is_pipe(str) || is_semicolon(str);
}

void	fatal(void)
{
	write(2, "error: fatal\n", 13);
	exit(1);
}

void	error(char *str, char *av)
{
	char	*msg = ft_strjointri(str, av, "\n");
	if (msg == NULL)
		fatal();
	write(2, msg, ft_strlen(msg));
	free(msg);
}

void	sc_close(int fd)
{
	if (0 > close(fd))
		fatal();
}

void	sc_dup2(int old_fd, int new_fd)
{
	sc_close(new_fd);
	if (0 > dup2(old_fd, new_fd))
		fatal();
	sc_close(old_fd);
}

void	sc_execve(char **av, char **env, int in)
{
	int	k;

	k = 0;
	while (av[k] && !is_separator(av[k]))
		k++;
	av[k] = NULL;
	sc_dup2(in, STDIN_FILENO);
	execve(*av, av, env);
	error("error: cannot execute ", *av);
	exit(1);
}

void	ex_cd(char **av)
{
	if (!av[1] || is_separator(av[1]) || (av[2] && !is_separator(av[2])))
		write(2, "error: cd: bad arguments\n", 25);
	else if (0 > chdir(av[1]))
		error("error: cd cannot change directory to ", av[1]);
}

void	ex_pipe(char **av, char **env, int *in)
{
	int	pp[2];
	int	pid;

	if (0 > pipe(pp))
		fatal();
	pid = fork();
	if (0 > pid)
		fatal();
	if (pid == 0)
	{
		sc_dup2(pp[1], 1);
		sc_close(pp[0]);
		sc_execve(av, env, *in);
	}
	sc_close(*in);
	*in = pp[0];
	sc_close(pp[1]);
}

void	ex_last(char **av, char **env, int *in)
{
	int	pid;

	pid = fork();
	if (0 > pid)
		fatal();
	if (0 == pid)
		sc_execve(av, env, *in);
	sc_close(*in);
	*in = dup(STDIN_FILENO);
	while (-1 != waitpid(-1, 0, 0))
		;
}

int	main(int ac, char **av, char **env)
{
	int	in = dup(0);
	int i;
	int	k;

	if (0 > in)
		fatal();
	i = 1;
	while (av[i])
	{
		while (av[i] && is_separator(av[i])) // skip separator(s)
			i++;
		if (av[i] == NULL)
			break ;

		k = i;
		while (av[k] && !is_separator(av[k]))
			k++; // find next sep to choose btw | and (; or null)

		if (0 == strcmp(av[i], "cd"))
			ex_cd(av + i);
		else if (is_pipe(av[k]))
			ex_pipe(av + i, env, &in);
		else
			ex_last(av + i, env, &in);
		while (av[i] && !is_separator(av[i]))
			i++; // go to next separator
	}
	sc_close(in);
	return 0;
	(void)ac;
}
