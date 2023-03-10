/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:43:52 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/02 18:25:24 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main:
* Finds stack size & initializes stack a,
* EXIT_FAILURE = 1 / EXIT_SUCCESS = 0
* system("leaks push_swap");
*/

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
		push_small(stack_a, stack_size);
	else
		push_big(stack_a, stack_size);
	return (EXIT_SUCCESS);
}
