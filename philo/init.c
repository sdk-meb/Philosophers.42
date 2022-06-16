/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:22:53 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/15 12:33:02 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	done_forks(t_id *philo, t_meo *forks, int naming)
{
	if (pthread_mutex_init(&(forks[naming]), NULL))
		return (1);
	philo->forks = forks;
	pthread_mutex_unlock(&(forks[naming]));
	return (0);
}

bool	creat_threads(t_id *philo)
{
	if (pthread_create(&(philo)->th_ph, NULL, &sit_to_table, philo))
		return (1);
	if (pthread_detach((philo)->th_ph))
		return (1);
	return (0);
}

void	provide(t_info *ug, int naming, t_meo *forks)
{
	t_id	philo;

	philo.ug = ug;
	philo.naming = naming;
	philo.neifork = naming + 1;
	philo.e_meal = ug->e_meals / ug->cp;
	if (done_forks(&philo, forks, naming))
		return ;
	if (creat_threads(&philo))
		return ;
	if (naming == ug->cp)
	{
		philo.neifork = 1;
		ug->e_meals += 42;
		ug->sit = 1;
		while (ug->sit == 1)
			usleep(0);
		while (ug->e_meals && ug->sit > 1 - (ug->cp))
			usleep(0);
		usleep(500 * ug->cp);
	}
	else
		provide(ug, naming + 1, forks);
	pthread_mutex_destroy(&(forks[naming]));
}

void	init_env(t_info *ug)
{
	t_meo	*forks;

	forks = (t_meo *) malloc(sizeof(forks) * (ug->cp + 1));
	if (!forks || pthread_mutex_init(&(forks[0]), NULL))
		return ;
	pthread_mutex_unlock(&(forks[0]));
	provide(ug, 1, forks);
	pthread_mutex_destroy(&(forks[0]));
	free((void *) forks);
}
