/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:30 by sanghan           #+#    #+#             */
/*   Updated: 2022/12/10 16:23:31 by sanghan          ###   ########.fr       */
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

void			*philo_loop(void *job);
unsigned long	get_time(void);
int				ft_usleep(int time);
int				philo_start(t_info *info);
int				init_input(t_info *info, int argc, char *argv[]);
int				ft_atoi(const char *str);
int				error_free(char *str, t_info *info, t_philo *philo, int cnt);
void			init_philo(t_info *info, t_philo *philo);
int				init_thread(t_info *info, t_philo *philo);
void			check_thread(t_info *info, t_philo *philo);
void			thread_end(t_info *info, t_philo *philo);
void			print_state(t_philo *philo, char *str);
#endif
