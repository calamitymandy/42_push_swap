/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:32:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/27 18:23:32 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
* Output: sa(swap a)
* swap top 2 elements of stack a
*/
void	do_sa(int *stack_a)
{
	int	temp;

	write (1, "sa\n", 3);
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}
/*
* Output: pa (push a)
* push top elmnt of B to top of A
* store top B elmnt in temp & move all B up 1 position
* Fill rest of B with -1's
*/

void	do_pa(int *stack_a, int *stack_b, size_t stack_size)
{
	size_t	i;
	int		temp;

	write (1, "pa\n", 3);
	temp = stack_b[0];
	i = 0;
	while (i < stack_size - 1 && stack_b[i + 1] > -1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	while (i < stack_size)
		stack_b[i++] = -1;
	i = stack_size;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
}

/*
* Output: ra(rotate a)
* send top elmnt A to bottom & move all other A elmnts up 1 position
*/
void	do_ra(int *stack_a, size_t stack_size)
{
	size_t	i;
	int		temp;

	write(1, "ra\n", 3);
	temp = stack_a[0];
	i = 0;
	while (i < stack_size - 1 && stack_a[i + 1] > -1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
}

/*
* Output: rra(reverse rotate a)
* send bottom elmnt A to top 
* & move all other A elmnts down 1 position
* 1st loop find last number's position
*/
void	do_rra(int *stack_a, size_t stack_size)
{
	size_t	i;
	int		temp;

	write (1, "rra\n", 4);
	i = stack_size -1;
	while (i > 0 && stack_a[i] == -1)
		i--;
	temp = stack_a[i];
	i++;
	while (--i > 0)
		stack_a[i] = stack_a[i - 1];
	stack_a[i] = temp;
}
