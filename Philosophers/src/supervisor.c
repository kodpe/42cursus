/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:54:12 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 23:15:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_philo *ph)
{
	t_time	t;
	int		is_dead;

	is_dead = 0;
	pthread_mutex_lock(ph->eat_mtx);
	t = time_ms();
	if (t - ph->last_eat_time >= ph->pm.time_to_die)
		is_dead = 1;
	pthread_mutex_unlock(ph->eat_mtx);
	if (is_dead)
	{
		pthread_mutex_lock(ph->stop_mtx);
		*ph->stop = 1;
		pthread_mutex_unlock(ph->stop_mtx);
		usleep(4200);
		pthread_mutex_lock(ph->log_mtx);
		t = time_ms() - ph->start_time;
		printf("%lld %d %s\n", t, ph->id, STR_DIE);
		pthread_mutex_unlock(ph->log_mtx);
		return (STOP);
	}
	return (CONTINUE);
}

static int	check_must_eat(t_philo *ph, int *nb_philo_done)
{
	if (ph->pm.must_eat == -1)
		return (CONTINUE);
	pthread_mutex_lock(ph->eat_mtx);
	if (ph->eat_count >= ph->pm.must_eat)
		*nb_philo_done += 1;
	pthread_mutex_unlock(ph->eat_mtx);
	if (*nb_philo_done == ph->pm.nb_philo)
	{
		pthread_mutex_lock(ph->stop_mtx);
		*ph->stop = 1;
		pthread_mutex_unlock(ph->stop_mtx);
		return (STOP);
	}
	return (CONTINUE);
}

void	supervisor(t_parent *p)
{
	int	nb_philo_done;
	int	i;

	usleep(5000);
	while (1)
	{
		nb_philo_done = 0;
		i = 0;
		while (i < p->nb_philo)
		{
			if (check_must_eat(&p->ph[i], &nb_philo_done))
				return ;
			if (check_death(&p->ph[i]))
				return ;
			i++;
		}
		usleep(1000);
	}
}
