/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:32:04 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/03 20:24:38 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
* Output: sb(swap b)
* swap top 2 elements of stack b
*/
void	do_sb(int *stack_b)
{
	int	temp;

	write (1, "sb\n", 3);
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
}

/*
* Output: pb (push b)
* push top elmnt of A to top of B
* store top A elmnt in temp & move all A up 1 position
* Fill rest of A with -1's
*/
void	do_pb(int *stack_a, int *stack_b, size_t stack_size)
{
	size_t	i;
	int		temp;

	write (1, "pb\n", 3);
	temp = stack_a[0];
	i = 0;
	while (i < stack_size -1 && stack_a[i + 1] > -1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	while (i < stack_size)
		stack_a[i++] = -1;
	i = stack_size;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
}
