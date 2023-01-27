/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:39:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/01/27 19:40:48 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack(int argc, char **argv);
t_stack		*get_stack_end(t_stack *stack);
void		stack_add(t_stack	**stack, t_stack *new);
t_stack		*stack_new(int value);

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
int			find_size(t_stack *stack);

/*UTILS*/
int			is_digit(char c);
long int	ft_atoi(const char *str);

#endif
