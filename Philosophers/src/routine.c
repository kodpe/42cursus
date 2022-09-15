/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:06:33 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 23:15:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	routine_think(t_philo *ph)
{
	if (stop(ph))
		return (STOP);
	log_philo(ph, STR_THINK);
	if (ph->eat_count == 0 && ph->id % 2 == 0)
		usleep(5000);
	if (ph->pm.nb_philo % 2 == 1)
	{
		if (ph->pm.time_to_sleep > ph->pm.time_to_eat)
		{
			if (smart_sleep(ph, ph->pm.time_to_eat / 2))
				return (STOP);
		}
		else
		{
			if (smart_sleep(ph, ph->pm.time_to_eat))
				return (STOP);
		}
	}
	return (CONTINUE);
}

static int	routine_fork(t_philo *ph)
{
	if (stop(ph))
		return (STOP);
	pthread_mutex_lock(ph->fork_left_mtx);
	log_philo(ph, STR_FORK);
	if (stop(ph) || ph->pm.nb_philo == 1)
	{
		pthread_mutex_unlock(ph->fork_left_mtx);
		return (STOP);
	}
	pthread_mutex_lock(ph->fork_right_mtx);
	log_philo(ph, STR_FORK);
	return (SUCCESS);
}

static int	routine_eat(t_philo *ph)
{
	int	is_stop;

	if (stop(ph))
	{
		pthread_mutex_unlock(ph->fork_right_mtx);
		pthread_mutex_unlock(ph->fork_left_mtx);
		return (STOP);
	}
	log_philo(ph, STR_EAT);
	pthread_mutex_lock(ph->eat_mtx);
	ph->last_eat_time = time_ms();
	ph->eat_count++;
	pthread_mutex_unlock(ph->eat_mtx);
	is_stop = smart_sleep(ph, ph->pm.time_to_eat);
	pthread_mutex_unlock(ph->fork_right_mtx);
	pthread_mutex_unlock(ph->fork_left_mtx);
	return (is_stop);
}

static int	routine_sleep(t_philo *ph)
{
	if (stop(ph))
		return (STOP);
	log_philo(ph, STR_SLEEP);
	if (smart_sleep(ph, ph->pm.time_to_sleep))
		return (STOP);
	return (CONTINUE);
}

void	*philo_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (routine_think(ph))
			break ;
		if (routine_fork(ph))
			break ;
		if (routine_eat(ph))
			break ;
		if (routine_sleep(ph))
			break ;
	}
	return (NULL);
}
