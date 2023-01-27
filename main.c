/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:43:52 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/01/27 19:40:44 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main:
* Check if input is correct, if so it initializes stacks a & b,
* assigns each value indexes and sorts the stacks.
* When sorting is done, we free the stacks and exits.
* EXIT_FAILURE = 1 / EXIT_SUCCESS = 0
*/

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		write(1, "slmt 2 nums", 11);
	else if (stack_size == 3)
		write(1, &stack_a, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		exit(EXIT_FAILURE);
	write(1, "ok", 2);
	//if (!input_ok(argv))
		//write(1, "Error\n", 6);
		//exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stack_size = find_size(stack_a);
	//crea_index(stack_a, stack_size +1);
	push_swap(&stack_a, &stack_b, stack_size);
	//free_stack(&stack_a);
	//free_stack(&stack_b);
	return (EXIT_SUCCESS);
}
