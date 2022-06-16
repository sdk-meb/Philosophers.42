/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:25:53 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/06/12 09:37:09 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	n;

	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
			i++;
	if (str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i] - 48);
		while (i++, str[i] >= '0' && str[i] <= '9')
			n = (str[i] - 48) + (10 * n);
	}
	else
		return (-1);
	if (str[i] || i > 10 || n > 2147483647)
		return (-1);
	return (n);
}
