/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:25:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 22:28:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_mutex(t_parent *p)
{
	int	i;

	i = -1;
	while (++i < p->nb_philo)
	{
		if (i % 2 == 0)
		{
			p->ph[i].fork_right_mtx = &p->fork[i];
			if (i == 0)
				p->ph[i].fork_left_mtx = &p->fork[p->nb_philo - 1];
			else
				p->ph[i].fork_left_mtx = &p->fork[i - 1];
		}
		if (i % 2 == 1)
		{
			p->ph[i].fork_left_mtx = &p->fork[i];
			if (i == 0)
				p->ph[i].fork_right_mtx = &p->fork[p->nb_philo - 1];
			else
				p->ph[i].fork_right_mtx = &p->fork[i - 1];
		}
		p->ph[i].eat_mtx = &p->eat_mtx[i];
		p->ph[i].log_mtx = &p->log_mtx;
		p->ph[i].stop_mtx = &p->stop_mtx;
	}
}

static void	mutex_destroy_tab(pthread_mutex_t *mutex, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}

static int	mutex_init_tab(pthread_mutex_t *mutex, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&mutex[i], NULL))
		{
			mutex_destroy_tab(mutex, i - 1);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

void	mutex_destroy(t_parent *p)
{
	pthread_mutex_destroy(&p->log_mtx);
	pthread_mutex_destroy(&p->stop_mtx);
	mutex_destroy_tab(p->eat_mtx, p->nb_philo);
	mutex_destroy_tab(p->fork, p->nb_philo);
	free(p->eat_mtx);
	free(p->fork);
	free(p->ph);
}

int	mutex_init(t_parent *p)
{
	if (pthread_mutex_init(&p->log_mtx, NULL))
		return (FAILURE);
	if (pthread_mutex_init(&p->stop_mtx, NULL))
	{
		pthread_mutex_destroy(&p->log_mtx);
		return (FAILURE);
	}
	if (mutex_init_tab(p->fork, p->nb_philo))
	{
		pthread_mutex_destroy(&p->log_mtx);
		pthread_mutex_destroy(&p->stop_mtx);
		return (FAILURE);
	}
	if (mutex_init_tab(p->eat_mtx, p->nb_philo))
	{
		mutex_destroy_tab(p->fork, p->nb_philo);
		pthread_mutex_destroy(&p->log_mtx);
		pthread_mutex_destroy(&p->stop_mtx);
		return (FAILURE);
	}
	assign_mutex(p);
	return (SUCCESS);
}
