/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:25:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 20:43:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPES_H
# define PHILO_TYPES_H

typedef long long	t_time;

typedef struct s_params
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_think;
	int	must_eat;
}	t_params;

typedef struct s_philo
{
	int				id;
	pthread_t		th;
	t_params		pm;
	t_time			start_time;

	pthread_mutex_t	*fork_left_mtx;
	pthread_mutex_t	*fork_right_mtx;
	pthread_mutex_t	*log_mtx;

	pthread_mutex_t	*stop_mtx;
	int				*stop;

	pthread_mutex_t	*eat_mtx;
	t_time			last_eat_time;
	int				eat_count;
}	t_philo;

typedef struct s_parent
{
	t_philo			*ph;
	int				nb_philo;
	t_params		pm;
	t_time			start_time;
	int				stop;

	pthread_mutex_t	*fork;
	pthread_mutex_t	*eat_mtx;
	pthread_mutex_t	log_mtx;
	pthread_mutex_t	stop_mtx;

}	t_parent;

#endif /* PHILO_TYPES_H */
