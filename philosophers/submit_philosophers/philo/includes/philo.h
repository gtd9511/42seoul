/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:30 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/14 17:53:45 by sanghan          ###   ########.fr       */
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

typedef struct s_info
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
	pthread_mutex_t	over_guard;
	pthread_mutex_t	*ready_guard;
	pthread_mutex_t	*death;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_philo
{
	int				p_id;
	int				is_die;
	int				eat_cnt;
	long long		t_start;
	long long		meal;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_info			*info;
}	t_philo;

void			print_state(t_philo *philo, char *str);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			eating(t_philo *philo);
void			*philo_loop(void *job);
int				ft_usleep(int time);
unsigned long	get_time(void);
int				ft_atoi(const char *str);
int				error_free(char *str, t_info *info, t_philo *philo, int cnt);
int				philo_start(t_info *info);
int				init_thread(t_info *info, t_philo *philo);
void			init_philo(t_info *info, t_philo *philo);
int				init_input(t_info *info, int argc, char *argv[]);
void			check_thread(t_info *info, t_philo *philo);
void			thread_end(t_info *info, t_philo *philo);
int				check_over_guard(t_info *info);
int				check_ready_guard(t_info *info);

#endif
