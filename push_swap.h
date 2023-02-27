/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:39:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/27 18:55:31 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

/*UTILS*/
char		**ft_split(const char *s, char c);
int			ft_strlen(const char *str);
int			is_digit(int c);
long int	ft_atoi(const char *str);
size_t		double_strlen(char	**str);
size_t		is_repeat(char **nums, size_t position);
void		crea_stack_b(int *stack_b, int stack_size);
size_t		is_sorted(int *stack, size_t stack_size);

/*PUSH_SWAP*/
int			*assign_index(int *stack_a, size_t stack_size);
void		push_short(int *stack_a, size_t stack_size);

/*A_MOVES*/
void		do_sa(int *stack_a);
void		do_pa(int *stack_a, int *stack_b, size_t stack_size);
void		do_ra(int *stack_a, size_t stack_size);
void		do_rra(int *stack_a, size_t stack_size);

/*B_MOVES*/
void		do_sb(int *stack_b);
void		do_pb(int *stack_a, int *stack_b, size_t stack_size);

#endif
