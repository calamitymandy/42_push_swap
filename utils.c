/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:37:55 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/23 13:38:16 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	is_sorted(int *stack, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size - 1 && stack[i] > 0)
	{
		if (stack[i] > stack[i + 1])
		return (0);
		i++;
	}
	return (1);
}

/*Create stack_b with as -1 as the lengtn of stack_size*/
void	crea_stack_b(int *stack_b, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		stack_b[i] = -1;
		i++;
	}
}

/* check if number in position given at each loop of valid_input is repeated
within the rest of numbers
Return: 1 if a duplicate is found, 0 if there are none. */
size_t	is_repeat(char **nums, size_t posnum)
{
	size_t	i;

	i = 0;
	while (i < posnum)
	{
		if (ft_atoi(nums[i]) == ft_atoi(nums[posnum]))
			return (1);
		i++;
	}
	return (0);
}

size_t	double_strlen(char	**str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
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
