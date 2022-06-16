/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:36:57 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/14 19:05:17 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parsing(char **guide, bool e_mea)
{
	t_info	ug;

	ug.cp = ft_atoi(guide[1]);
	ug.die_t = ft_atoi(guide[2]);
	ug.eat_t = ft_atoi(guide[3]);
	ug.slp_t = ft_atoi(guide[4]);
	ug.e_meals = -42;
	ug.sit = 0;
	ug.dt = -42;
	if (e_mea)
		ug.e_meals = ft_atoi(guide[5]) * ug.cp;
	if (ug.cp > 200 || ug.cp <= 0 || ug.die_t < 60 || ug.eat_t < 60
		|| ug.slp_t < 60 || (e_mea && ug.e_meals < 0))
	{
		printf("Just the (+)(int)digits should exist by parameters\n");
		return ;
	}
	if (ug.cp % 2)
		ug.dt = ug.cp;
	init_env(&ug);
}
