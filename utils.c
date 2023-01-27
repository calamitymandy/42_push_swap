/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:37:55 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/01/27 19:08:52 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atoi(const char *str)
{
	long int	num;
	int			neg;
	int			i;

	num = 0;
	neg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}
