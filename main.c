/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:43:52 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/23 13:36:32 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main:
* Finds stack size & initializes stack a,
* EXIT_FAILURE = 1 / EXIT_SUCCESS = 0
*/

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
		//free_split(nums);
	}
	if (nums_size < stack_size)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

/* find how many args there is or how many numbers are presents in string*/
size_t	find_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
				size++;
			i++;
		}
	}
	else
		size = argc -1;
	return (size);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	size_t	stack_size;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_size = find_size(argc, argv);
	stack_a = crea_stack(argc, argv, stack_size);
	if (!stack_a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a[stack_size] = '\0';
	if (stack_size < 6)
		push_short(stack_a, stack_size);
	//else
		//push_long(stack_a, stack_size);
	//write (1, &stack_a, 1);
	printf("\n");
	printf("check stack_a[0]: %d\n", stack_a[0]);
	printf("check stack_a[1]: %d\n", stack_a[1]);
	return (EXIT_SUCCESS);
}
