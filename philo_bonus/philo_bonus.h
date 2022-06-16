/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:23:03 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/16 08:23:37 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct timeval	t_val;

typedef struct s_id{
	int				naming;
	int				neifork;
	int				e_meal;
	int				t_fork;
	bool			will;
	int				status;
	pid_t			mychild;
	t_val			time;
	pthread_t		th_ph;

	struct s_info	*ug;
}					t_id;

typedef struct s_info{
	int		cp;
	int		die_t;
	int		eat_t;
	int		slp_t;
	int		e_meals;
	int		dt;
	sem_t	*sem;
	sem_t	*pen;

	short	sit;
}				t_info;

void	parsing(char **guide, bool e_mea);
int		ft_atoi(const char *str);

void	init_env(t_info *ug);

void	ft_usleep(t_id *philo, long long time);
void	*sit_to_table(void *pid);
void	livability(t_id *philo, t_info *ug);
void	team_compatibility(t_id *philo, t_info *ug, bool dt);
void	nap_sleeping(t_id *philo, t_info *ug);
void	mindset_philo(t_id *philo, t_info *ug);
void	mealeating(t_id *philo, t_info *ug);

#endif
