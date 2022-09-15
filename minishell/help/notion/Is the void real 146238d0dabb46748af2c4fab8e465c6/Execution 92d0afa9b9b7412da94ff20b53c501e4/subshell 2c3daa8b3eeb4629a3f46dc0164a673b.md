# subshell

[**info subshell**](https://unix.stackexchange.com/questions/138463/do-parentheses-really-put-the-command-in-a-subshell)

minimishell

```bash
# simple test
x=42 && echo $x   # => 42
x=42 && (echo $x) # => 42 parceque la variable a ete transmise au subshell

(y=42 && echo $y) # => 42
(y=42) && echo $y # => rien parceque la variable a ete set que dans le subshell

# subshell in shubshell
((echo 11-a || echo 11-b) && (echo 12-a || echo 12-b)) && echo c
#.....................subshell 1......................
# ......subshell 11.....      ......subshell 12......
```

```c
// fork + recursive main ? or fork + execve minishell ?

// recursive main
#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	if (--ac)
		return (printf("%d ", ac + main(ac, av, envp)));
}
```

```c
// fork + recursive main

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **envp)
{
	int	pid;

	if (--ac)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
			return (printf("%d ", ac + main(ac, av, envp)));
		waitpid(pid, NULL, 0);
		printf("\n");
		return (0);
	}
}
```