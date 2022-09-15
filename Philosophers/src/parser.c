/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:27:19 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/29 19:32:54 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	usage(void)
{
	printf("./philo <1> <2> <3> <4> [5]\n");
	printf(" <1> number_of_philosophers (⇔ nb_of_fork)\n");
	printf(" <2> time_to_die (ms)\n");
	printf(" <3> time_to_eat (ms)\n");
	printf(" <4> time_to_sleep (ms)\n");
	printf(" [5] number_of_times_each_philosopher_must_eat (optional)\n");
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	return (nbr * sign);
}

static int	ft_cnt_only_digit(char *str, int max_digit)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (i == 0 || i > max_digit)
		return (1);
	return (0);
}

static int	atoi_args(t_parent *p, char **av)
{
	memset(p, 0, sizeof(t_parent));
	p->pm.nb_philo = ft_atoi(av[1]);
	p->nb_philo = p->pm.nb_philo;
	p->pm.must_eat = -1;
	if (av[5])
		p->pm.must_eat = ft_atoi(av[5]);
	p->pm.time_to_die = ft_atoi(av[2]);
	p->pm.time_to_eat = ft_atoi(av[3]);
	p->pm.time_to_sleep = ft_atoi(av[4]);
	p->pm.time_to_think = 0;
	if (p->nb_philo == 0 || p->pm.must_eat == 0)
		return (ERR_ARG);
	return (SUCCESS);
}

int	parser(int ac, char **av, t_parent *p)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (usage(), ERR_ARG);
	i = 1;
	while (i < ac)
	{
		if (ft_cnt_only_digit(av[i], 10))
			return (usage(), ERR_ARG);
		i++;
	}
	if (atoi_args(p, av))
		return (ERR_ARG);
	p->stop = 0;
	p->start_time = 0;
	return (SUCCESS);
}
