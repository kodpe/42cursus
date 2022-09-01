/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/31 21:08:59 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include "philo_types.h"

# define STOP		1
# define CONTINUE	0
# define SUCCESS	0
# define FAILURE	1
# define ERR_ARG	2
# define STR_FORK	"has taken a fork"
# define STR_EAT	"is eating"
# define STR_SLEEP	"is sleeping"
# define STR_THINK	"is thinking"
# define STR_DIE	"died"

int		init(t_parent *p);

void	log_philo(t_philo *ph, char *msg);

int		mutex_init(t_parent *p);
void	mutex_destroy(t_parent *p);

int		parser(int ac, char **av, t_parent *p);

void	*philo_routine(void *arg);

void	supervisor(t_parent *p);

t_time	time_ms(void);
t_time	sc_time_ms(void);
int		stop(t_philo *ph);
int		smart_sleep(t_philo *ph, t_time sleep_ms);

#endif /* PHILO_H */
