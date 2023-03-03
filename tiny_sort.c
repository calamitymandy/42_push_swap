/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:13:41 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/02 18:25:59 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if 1st num is == size -1 it's the max number.
 * DO COMMENT !!!
 */

void	sort_three(int *stack_a, size_t stack_size)
{
	if (stack_a[0] == stack_size - 2)
	{
		if (stack_a[1] == stack_size - 1)
			do_rra(stack_a, stack_size);
		else
			do_sa(stack_a);
	}
	else if (stack_a[0] == stack_size - 1)
	{
		if (stack_a[1] == stack_size - 2)
		{
			do_ra(stack_a, stack_size);
			do_sa(stack_a);
		}
		else
		{
			do_rra(stack_a, stack_size);
			do_rra(stack_a, stack_size);
		}
	}
	else
	{
		do_rra(stack_a, stack_size);
		do_sa(stack_a);
	}
}

/*size == 5 -> Push 0 & 1 to B. Order the other 3 nums in A with sort_three. 
 * If B is sorted swaps the 2 numbers to push back to A first the number 1,
 * then the number 0.
 *size == 4 -> Push 0 to B. Order the 3 other nums with sort_three.
 * Push back 0 in B to A.
 *size == 3 -> sort_three
 * */

void	tiny_sort(int *stack_a, int *stack_b, size_t stack_size)
{
	size_t	i;

	i = -1;
	while (++i < stack_size && stack_size > 3)
	{
		if (stack_a[0] == 0)
			do_pb(stack_a, stack_b, stack_size);
		else if (stack_size == 5 && stack_a[0] == 1)
			do_pb(stack_a, stack_b, stack_size);
		else
			do_ra(stack_a, stack_size);
	}
	if (!is_sorted(stack_a, stack_size))
		sort_three(stack_a, stack_size);
	if (stack_size > 3)
	{
		if (is_sorted(stack_b, stack_size) && stack_size == 5)
			do_sb(stack_b);
		do_pa(stack_a, stack_b, stack_size);
		if (stack_size == 5)
			do_pa(stack_a, stack_b, stack_size);
	}
}
