/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:43:52 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/15 15:17:22 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main:
* Finds stack size & initializes stack a,
* EXIT_FAILURE = 1 / EXIT_SUCCESS = 0
*/

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
			fill_stack(nums, stack, nums_size);
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
	char	**split;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_size = find_size(argc, argv);
	printf("stack size: %d\n", stack_size);
	//stack_a = crea_stack(argc, argv, stack_size);
	split = ft_split(argv[1], ' ');
	printf("%s\n", split[0]);
	printf("%s\n", split[1]);
	printf("%s\n", split[2]);
	printf("%s\n", split[3]);
	printf("%s\n", split[4]);
	//crea_index(stack_a, stack_size +1);
	return (EXIT_SUCCESS);
}
