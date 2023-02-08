/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:43:52 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/08 17:01:59 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main:
* Finds stack size & initializes stack a,
* EXIT_FAILURE = 1 / EXIT_SUCCESS = 0
*/

int	crea_stack(int	argc, char **argv, int stack_size)
{
	//TO DO
}

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
	stack = crea_stack(argc, argv, stack_size);
	//crea_index(stack_a, stack_size +1);
	push_swap(&stack_a, &stack_b, stack_size);
	return (EXIT_SUCCESS);
}
