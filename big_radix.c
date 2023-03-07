/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:27:10 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/03 17:39:04 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* at 1st num_in_bits is stack_a[0], then we move the cursor on the bits of 
 * "bit_i" position to the left. the number on the right will be the result:
 * ex: 
 *  8       : 1000
 *  8>>2    :   10
 * If num_in_bits == 1, (num_in_bits & 1) == 1
 * If num_in_bits == 0, (num_in_bits & 1) == 0
 */
size_t	check_bits(int num_in_bits, size_t bit_i)
{
	if (!num_in_bits)
		return (1);
	num_in_bits >>= bit_i;
	if (num_in_bits & 1)
		return (0);
	else
		return (1);
}

/* If check_bits == 0 (it means that num in bits in stack_a[0] has 0 
 * on the bit_i position), we push to B.
 * if not no we just rotate stack_a to go on with the analisis of stack_a.
 * Until i reach stack_size.
 */
void	use_stacks(int *stack_a, int *stack_b, size_t bit_i, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size)
	{
		if (check_bits(stack_a[0], bit_i))
			do_pb(stack_a, stack_b, stack_size);
		else
			do_ra(stack_a, stack_size);
		i++;
	}
}

/* Push back fron B to A */
void	join_stacks(int *stack_a, int *stack_b, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size && stack_b[0] > -1)
	{
		do_pa(stack_a, stack_b, stack_size);
		i++;
	}
}
