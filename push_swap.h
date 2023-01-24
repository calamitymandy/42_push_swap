/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:39:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/01/24 18:51:18 by amdemuyn         ###   ########.fr       */
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
	int		value;
	int		index;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack(int argc, char **argv);
void		crea_index(t_stack *stack_a, int argc);

int			find_size(t_stack *stack);
int			input_ok(char **argv);

#endif
