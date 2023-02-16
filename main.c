/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:43:52 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/16 20:00:16 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main:
* Finds stack size & initializes stack a,
* EXIT_FAILURE = 1 / EXIT_SUCCESS = 0
*/
size_t	valid_input(char **nums, int *stack, size_t nums_size)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	temp = *nums;
	while (i < ft_strlen(temp))
	{
		if (ft_atoi(nums[i]) > INT_MAX || ft_atoi(nums[i]) < INT_MIN)
			return (0);
		//if is_repeat(nums, i)
			//return (0);
		while (j < nums_size)
		{
			if (ft_atoi(nums[i]) == 0)
				return (0);
			j++;
		}
		j = -1;
		i++;
	}
	return (1);
}

int	*crea_stack(int argc, char **argv, int stack_size)
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
	while (++i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (valid_input(nums, stack, nums_size))
			write (1, "ok", 2);
			//fill_stack(nums, stack, nums_size);
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
int	find_size(int argc, char **argv)
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
	int		stack_size;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_size = find_size(argc, argv);
	stack_a = crea_stack(argc, argv, stack_size);
	write (1, &stack_a, 1);
	//printf("stack: %d\n", *stack_a);
	return (EXIT_SUCCESS);
}
