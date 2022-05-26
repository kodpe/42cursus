/**
	waitpida investigation
**/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	int	pid1 = fork();
	if (pid1 == -1) {
		printf("Error creating process 1 -fork failed\n");
		return (1);
	}
	if (pid1 == 0) {
		printf("child process pid 1: %d : %d\n", pid1, getpid());
		return (0);
	}

	int	pid2 = fork();
	if (pid2 == -1) {
		printf("Error creating process 2 -fork failed\n");
		return (2);
	}
	if (pid2 == 0) {
		printf("child process pid 2: %d : %d\n", pid2, getpid());
		return (0);
	}
	printf("waited for %d\n", pid1);
	waitpid(pid1, NULL, 0);

	printf("waited for %d\n", pid2);
	waitpid(pid2, NULL, 0);

	return (0);
}

