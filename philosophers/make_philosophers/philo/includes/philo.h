/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:30 by sanghan           #+#    #+#             */
/*   Updated: 2022/11/30 14:45:24 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_philo;
	int				ready;
	int				time_die;
	int				time_slp;
	int				time_eat;
	int				must_eat;
	int				chk_meal;
	int				over;
	long long		start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
}	t_philo;

typedef struct s_thread
{
	int				p_id;
	int				is_die;
	int				eat_cnt;
	long long		t_start;
	long long		meal;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_philo			*philo;
}	t_thread;
#endif
