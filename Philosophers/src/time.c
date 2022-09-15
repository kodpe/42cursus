/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:02:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 20:37:10 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	sc_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

t_time	time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	stop(t_philo *ph)
{
	int	is_stop;

	pthread_mutex_lock(ph->stop_mtx);
	is_stop = *ph->stop;
	pthread_mutex_unlock(ph->stop_mtx);
	return (is_stop);
}

int	smart_sleep(t_philo *ph, t_time sleep_ms)
{
	t_time	end;

	end = time_ms() + sleep_ms;
	while (time_ms() < end)
	{
		if (stop(ph))
			return (STOP);
		usleep(500);
	}
	return (CONTINUE);
}
