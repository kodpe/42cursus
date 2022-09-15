/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:50:19 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 20:53:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	copy_params(const t_params *src, t_params *dst)
{
	dst->nb_philo = src->nb_philo;
	dst->must_eat = src->must_eat;
	dst->time_to_die = src->time_to_die;
	dst->time_to_eat = src->time_to_eat;
	dst->time_to_sleep = src->time_to_sleep;
	dst->time_to_think = src->time_to_think;
}

static int	malloc_philo(t_parent *p)
{
	p->ph = malloc(sizeof(t_philo) * p->nb_philo);
	if (!p->ph)
		return (FAILURE);
	p->fork = malloc(sizeof(pthread_mutex_t) * p->nb_philo);
	if (!p->fork)
		return (free(p->ph), FAILURE);
	p->eat_mtx = malloc(sizeof(pthread_mutex_t) * p->nb_philo);
	if (!p->eat_mtx)
		return (free(p->fork), free(p->ph), FAILURE);
	return (SUCCESS);
}

int	init(t_parent *p)
{
	int	i;

	p->start_time = sc_time_ms();
	if (p->start_time == -1)
		return (FAILURE);
	if (malloc_philo(p))
		return (FAILURE);
	i = 0;
	while (i < p->nb_philo)
	{
		memset(&p->ph[i], 0, sizeof(t_philo));
		copy_params((const t_params *)&p->pm, &p->ph[i].pm);
		p->ph[i].id = i + 1;
		p->ph[i].stop = &p->stop;
		p->ph[i].start_time = p->start_time;
		p->ph[i].last_eat_time = p->start_time;
		i++;
	}
	return (SUCCESS);
}
