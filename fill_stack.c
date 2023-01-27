/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:19:50 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/01/27 19:40:40 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*get_stack_end(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);	
}

void	stack_add(t_stack	**stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_end(*stack);
	tail->next = NULL;
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	num;
	int			i;

	stack_a = NULL;
	num = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			write(1, "Error\n", 6);
		if (i == 1)
			stack_a = stack_new((int)num);
		else
			stack_add(&stack_a, stack_new((int)num));
		i++;
	}
	return (stack_a);
}
