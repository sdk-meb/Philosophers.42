/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:36:08 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/12 10:06:51 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **guide)
{
	if (argc != 6 && argc != 5)
		return (1);
	parsing(guide, argc % 5);
	return (0);
}