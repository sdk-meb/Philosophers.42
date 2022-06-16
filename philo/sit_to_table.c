/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:49:13 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/16 08:22:45 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_id *philo, long long time)
{
	long long	time_now;
	long long	start_time;
	t_val		s_time;

	start_time = philo->time.tv_sec * 1000000 + philo->time.tv_usec;
	time = time * 1000 + start_time;
	while (!gettimeofday(&s_time, NULL))
	{
		time_now = s_time.tv_sec * 1000000 + s_time.tv_usec;
		if (time_now >= time)
			return ;
	}
}

void	team_compatibility(t_id *philo, t_info *ug, bool dt)
{
	if (dt)
		philo->t_fork = 2;
	if (!(ug->cp % 2) || ug->cp == 1)
		return ;
	if (ug->cp % 2 && ug->dt++ == ug->cp)
			ug->dt = 1;
	if (ug->cp % 2 && ug->dt == philo->naming)
		ft_usleep(philo, ug->eat_t);
}

void	order(t_id *philo, int e_meals, int t_fork)
{
	philo->e_meal = e_meals;
	philo->t_fork = t_fork;
}

void	livability(t_id *philo, t_info *ug)
{
	if (ug->cp == 1)
		order (philo, 0, 1);
	else if ((ug->cp % 2) * ug->eat_t + ug->eat_t < ug->die_t)
		team_compatibility(philo, ug, 1);
	else if (!(ug->cp % 2) || ug->eat_t <= ug->die_t)
	{
		order (philo, philo->naming % 2, (philo->naming % 2) * 2);
		if (ug->cp % 2)
			philo->e_meal = 0;
	}
	else
		order (philo, (1 + (philo->naming % (ug->cp - 1))) % 2,
			(philo->naming % 2) * 2);
}

void	*sit_to_table(void *phlo)
{
	t_id	*philo;
	t_info	*ug;

	philo = (t_id *)phlo;
	ug = philo->ug;
	while (ug->sit == 0)
		usleep(0);
	philo->will = 0;
	gettimeofday(&philo->time, NULL);
	livability(philo, ug);
	if (philo->naming % 2 && philo->naming - ug->cp)
		mealeating(philo, ug);
	else
		mindset_philo(philo, ug);
	return (NULL);
}
