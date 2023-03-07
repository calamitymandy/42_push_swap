/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:52:11 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/03 18:31:57 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * If stack[i + 1] is less than -1, no index was assigned, so we've reached 
 * the end of numbers in stack.
 *
 * Returns 1 if the stack is sorted, 0 otherwise
 */
size_t	is_sorted(int *stack, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size - 1 && stack[i + 1] > -1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* 
 * Assign index at each number comparing it to every other number of stack
 * to make sorting easier
 * When index is assigned, all numbers are positive (0, 1, 2... etc)
 */
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
void	push_small(int *stack_a, size_t stack_size)
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
		free(stack_b);
	}
	free(stack_a);
}

/* 1st loop all nums in bits with 0 on the right are pushed to B
 * then pushed back to A
 * 2nd loop all nums in bits with 0 on the 2nd position to the left 
 * are pushed to B
 * then pushed back to A
 * etc... 
 * until stack_a is sorted.
*/
void	push_big(int *stack_a, size_t stack_size)
{
	int		*temp;
	int		*stack_b;
	size_t	i;

	i = -1;
	temp = stack_a;
	stack_a = assign_index(stack_a, stack_size);
	free(temp);
	stack_b = malloc(sizeof(int) * (stack_size + 1));
	if (stack_b)
	{
		stack_b[stack_size] = '\0';
		crea_stack_b(stack_b, stack_size);
		while (!is_sorted(stack_a, stack_size))
		{
			use_stacks(stack_a, stack_b, ++i, stack_size);
			join_stacks(stack_a, stack_b, stack_size);
		}
		free(stack_b);
	}
	free(stack_a);
}

/*printf("\n");
printf("check stack_a[0]: %d\n", stack_a[0]);
printf("check stack_a[1]: %d\n", stack_a[1]);
printf("check stack_a[2]: %d\n", stack_a[2]);
printf("check stack_a[3]: %d\n", stack_a[3]);
printf("check stack_a[4]: %d\n", stack_a[4]);
printf("check stack_a[5]: %d\n", stack_a[5]);
*/