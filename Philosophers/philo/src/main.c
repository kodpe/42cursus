/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:03:28 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 22:33:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philo(t_parent *p)
{
	int	i;

	usleep(5000);
	i = 0;
	while (i < p->nb_philo)
	{
		pthread_join(p->ph[i].th, NULL);
		i++;
	}
}

static int	create_philo(t_parent *p)
{
	int	i;

	i = 0;
	while (i < p->nb_philo)
	{
		if (pthread_create(&p->ph[i].th, NULL, &philo_routine, &p->ph[i]))
		{
			while (--i)
				pthread_join(p->ph[i].th, NULL);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

void	log_philo(t_philo *ph, char *msg)
{
	t_time	t;
	int		is_stop;

	pthread_mutex_lock(ph->stop_mtx);
	is_stop = *ph->stop;
	pthread_mutex_unlock(ph->stop_mtx);
	if (is_stop)
		return ;
	pthread_mutex_lock(ph->log_mtx);
	t = time_ms() - ph->start_time;
	printf("%lld %d %s\n", t, ph->id, msg);
	pthread_mutex_unlock(ph->log_mtx);
}

int	main(int ac, char **av)
{
	t_parent	p;

	if (parser(ac, av, &p))
		return (ERR_ARG);
	if (init(&p))
		return (EXIT_FAILURE);
	if (mutex_init(&p))
	{
		free(p.eat_mtx);
		free(p.fork);
		free(p.ph);
		return (EXIT_FAILURE);
	}
	if (create_philo(&p))
	{
		mutex_destroy(&p);
		return (EXIT_FAILURE);
	}
	supervisor(&p);
	join_philo(&p);
	mutex_destroy(&p);
	return (EXIT_SUCCESS);
}
