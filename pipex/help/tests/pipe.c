/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:04:31 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/22 23:30:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// NEED CLOSE ALL PIPES IF ON FAIL close()

int	main(int ac, char **av, char **env)
{
	if (ac != 2)
	{
		fprintf(stderr, "error arg\n");
		exit(1);
	}
	int	n = atoi(av[1]);
	fprintf(stderr, "main process catch %d\n", n);

	int	fd[3][2];

	for (int i = 0; i < 3; i++) {
		if (0 > pipe(fd[i]))
			return (1);
	}

	int	pid1 = fork();
	if (pid1 < 0) {
		return (2);
	}
	if (pid1 == 0) {
		// child process 1
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);

		int x;
		if (read(fd[0][0], &x, sizeof(int)) < 0) {
			return (3);
		}

		x += 5;
		if (write(fd[1][1], &x, sizeof(int)) < 0) {
			return (4);
		}
		close(fd[0][0]);
		close(fd[1][1]);
		return (0);
	}

	int pid2 = fork();
	if (pid2 < 0) {
		return (5);
	}
	if (pid2 == 0) {
		// child process 2
		close(fd[0][1]);
		close(fd[0][0]);
		close(fd[1][1]);
		close(fd[2][0]);

		int x;
		if (read(fd[1][0], &x, sizeof(int)) < 0) {
			return (6);
		}

		x += 5;
		if (write(fd[2][1], &x, sizeof(int)) < 0) {
			return (7);
		}
		close(fd[1][0]);
		close(fd[2][1]);
		return (0);
	}
	// here parent process
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);

	int	x = n;
	if (write(fd[0][1], &x, sizeof(int)) < 0) {
		return (8);
	}
	if (read(fd[2][0], &x, sizeof(int)) < 0) {
		return (9);
	}
	close(fd[0][1]);
	close(fd[2][0]);

		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);

	fprintf(stderr, "main process done ! result is %d !\n", x);
	(void)env;
	return (0);
}
