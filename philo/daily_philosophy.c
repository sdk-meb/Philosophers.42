/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily_philosophy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:16:12 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/16 08:06:13 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cemetery_door(t_id *philo, t_info *ug, long agony)
{
	if (agony > 0)
		ft_usleep(philo, agony);
	if (!ug->sit)
		return ;
	pthread_mutex_lock(&(philo->forks)[0]);
	gettimeofday(&philo->time, NULL);
	agony = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	printf(" ◦ %ld : %d is died\n", agony, philo->naming);
	while (1)
		ug->sit = 0;
}

void	take_fork(t_id *philo, t_info *ug)
{
	long			time;

	if (philo->t_fork == 2 && ug->eat_t * 2 > ug->die_t && philo->will++)
		cemetery_door(philo, philo->ug, -1);
	pthread_mutex_lock(&(philo->forks)[philo->naming]);
	gettimeofday(&philo->time, NULL);
	time = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	pthread_mutex_lock(&(philo->forks)[0]);
	printf(" ◦ %ld : %d has taken a fork\n", time, philo->naming);
	pthread_mutex_unlock(&(philo->forks)[0]);
	if (philo->t_fork != 2)
		return ;
	pthread_mutex_lock(&(philo->forks)[philo->neifork]);
	gettimeofday(&philo->time, NULL);
	time = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	pthread_mutex_lock(&(philo->forks)[0]);
	printf(" ◦ %ld : %d has taken a fork\n", time, philo->naming);
	pthread_mutex_unlock(&(philo->forks)[0]);
}

void	mealeating(t_id *philo, t_info *ug)
{
	long	time;

	if (ug->e_meals && philo->e_meal-- <= 0)
	{
		ug->sit--;
		return ;
	}
	if (philo->t_fork)
		take_fork(philo, ug);
	if (philo->t_fork != 2)
		cemetery_door(philo, ug, ug->die_t);
	gettimeofday(&philo->time, NULL);
	time = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	pthread_mutex_lock(&(philo->forks)[0]);
	printf(" ◦ %ld : %d is eating\n", time, philo->naming);
	pthread_mutex_unlock(&(philo->forks)[0]);
	if (ug->eat_t > ug->die_t)
		cemetery_door(philo, ug, ug->eat_t);
	ft_usleep(philo, ug->eat_t);
	if (!ug->sit && !ug->e_meals)
		return ;
	pthread_mutex_unlock(&(philo->forks)[philo->naming]);
	pthread_mutex_unlock(&(philo->forks)[philo->neifork]);
	nap_sleeping(philo, ug);
}

void	nap_sleeping(t_id *philo, t_info *ug)
{
	long	time;

	gettimeofday(&philo->time, NULL);
	time = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	pthread_mutex_lock(&(philo->forks)[0]);
	printf(" ◦ %ld : %d is sleeping\n", time, philo->naming);
	pthread_mutex_unlock(&(philo->forks)[0]);
	if (ug->slp_t + ug->eat_t > ug->die_t)
		cemetery_door(philo, ug, ug->die_t - ug->eat_t);
	ft_usleep(philo, ug->slp_t);
	if (ug->sit || ug->e_meals)
	{
		gettimeofday(&philo->time, NULL);
		mindset_philo(philo, ug);
	}
}

void	mindset_philo(t_id *philo, t_info *ug)
{
	long	time;

	time = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	pthread_mutex_lock(&(philo->forks)[0]);
	printf(" ◦ %ld : %d is thinking\n", time, philo->naming);
	pthread_mutex_unlock(&(philo->forks)[0]);
	team_compatibility(philo, ug, 0);
	ft_usleep(philo, ug->eat_t - ug->slp_t);
	if (ug->sit || ug->e_meals)
		mealeating(philo, ug);
}
