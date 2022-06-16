/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:22:53 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/15 12:45:33 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	creat_threads(t_id *philo)
{
	if (pthread_create(&(philo)->th_ph, NULL, &sit_to_table, philo))
		return (1);
	if (pthread_detach((philo)->th_ph))
		return (1);
	return (0);
}

void	provide(t_info *ug, int naming)
{
	t_id	philo;

	philo.ug = ug;
	philo.naming = naming;
	philo.neifork = naming + 1;
	philo.e_meal = ug->e_meals / ug->cp;
	if (creat_threads(&philo))
		return ;
	if (naming == ug->cp)
	{
		ug->e_meals += 42;
		ug->sit = 1;
		while (ug->sit >= 1)
			usleep(0);
		while (ug->e_meals && ug->sit > 1 - (ug->cp))
			usleep(0);
	}
	else
		provide(ug, naming + 1);
	if (philo.mychild != -1)
		kill(philo.mychild, SIGQUIT);
}

void	init_env(t_info *ug)
{
	sem_unlink("forkss");
	ug->sem = sem_open("forkss", O_CREAT | O_EXCL, 777, ug->cp);
	sem_unlink("penn");
	ug->pen = sem_open("penn", O_CREAT | O_EXCL, 777, 1);
	provide(ug, 1);
	sem_close(ug->sem);
	sem_close(ug->pen);
}
