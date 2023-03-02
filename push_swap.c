/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:52:11 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/27 18:24:13 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assign index at each number comparing it to every other number of stack
 * to make sorting easier
 * When index is assigned, all numbers are positive */

int	*assign_index(int *stack_a, size_t stack_size)
{
	size_t	i;
	size_t	j;
	size_t	index;
	int		*stack_index;

	i = -1;
	j = -1;
	index = 0;
	stack_index = malloc(sizeof(int) * (stack_size + 1));
	if (!stack_index)
		return (NULL);
	stack_index[stack_size] = '\0';
	while (++i < stack_size)
	{
		while (++j < stack_size)
			if (stack_a[i] > stack_a[j])
				index++;
		stack_index[i] = index;
		index = 0;
		j = -1;
	}
	return (stack_index);
}

/* push_short: assign index to stack_a & initialize stack_b
 * if size 2 & unsorted, we swap the two nums
 * else we do the tiny_sort
 * temp to avoid leaks, bc we assign a new memory direction with
 * assign_index
*/
void	push_short(int *stack_a, size_t stack_size)
{
	int	*stack_b;
	int	*temp;

	temp = stack_a;
	stack_a = assign_index(stack_a, stack_size);
	free(temp);
	stack_b = malloc(sizeof(int) * (stack_size + 1));
	if (stack_b)
	{
		stack_b[stack_size] = '\0';
		crea_stack_b(stack_b, stack_size);
		if (stack_size <= 2 && !is_sorted(stack_a, stack_size))
			do_sa(stack_a);
		else if (!is_sorted(stack_a, stack_size))
			tiny_sort(stack_a, stack_b, stack_size);
		printf("\n");
		printf("check stack_a[0]: %d\n", stack_a[0]);
		printf("check stack_a[1]: %d\n", stack_a[1]);
		printf("check stack_a[2]: %d\n", stack_a[2]);
		printf("check stack_a[3]: %d\n", stack_a[3]);
		printf("check stack_a[4]: %d\n", stack_a[4]);
		free(stack_b);
	}
	free(stack_a);
}
