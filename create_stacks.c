/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:59:49 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/03 19:06:19 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **nums)
{
	size_t	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

/*Create stack_b with as -1 as the length of stack_size*/
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

/*Fill stack_a with correct numbers*/
void	fill_stack(char **nums, int *stack, size_t *nums_size)
{
	size_t	i;

	i = 0;
	while (i < double_strlen(nums))
	{
		stack[*nums_size] = ft_atoi(nums[i]);
		*nums_size += 1;
		i++;
	}
}

/* check if input is betweeen size of an int
 * check if there is duplicates
 * check if numbers are int whith 2nd passage in valid_input with nums_size
 * incremented at first passage in fill_stack.
 * If everything ok return (1)
 */
size_t	valid_input(char **nums, int *stack, size_t nums_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < double_strlen(nums))
	{
		if (ft_atoi(nums[i]) > INT_MAX || ft_atoi(nums[i]) < INT_MIN)
			return (0);
		if (is_repeat(nums, i))
			return (0);
		while (j < nums_size)
		{
			if (ft_atoi(nums[i]) == stack[j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	*crea_stack(int argc, char **argv, size_t stack_size)
{
	size_t	i;
	size_t	nums_size;
	int		*stack;
	char	**nums;

	i = 0;
	nums_size = 0;
	stack = malloc(sizeof(int) * (stack_size +1));
	if (!stack)
		return (NULL);
	stack[stack_size] = '\0';
	while (++i < (size_t)argc)
	{
		nums = ft_split(argv[i], ' ');
		if (valid_input(nums, stack, nums_size))
			fill_stack(nums, stack, &nums_size);
		free_split(nums);
	}
	if (nums_size < stack_size)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
