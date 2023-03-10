/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:39:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/03/03 20:25:25 by amdemuyn         ###   ########.fr       */
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
size_t		is_repeat(char **nums, size_t position);
size_t		double_strlen(char	**str);
int			ft_strlen(const char *str);
int			is_digit(int c);
long int	ft_atoi(const char *str);

/*SPLIT*/
char		**ft_split(const char *s, char c);
char		*ft_splat(size_t i, const char	*s, char c, char **split);

/*CREATE_STACKS*/
void		free_split(char **nums);
void		crea_stack_b(int *stack_b, int stack_size);
void		fill_stack(char **nums, int *stack, size_t *nums_size);
size_t		valid_input(char **nums, int *stack, size_t nums_size);
int			*crea_stack(int argc, char **argv, size_t stack_size);

/*PUSH_SWAP*/
size_t		is_sorted(int *stack, size_t stack_size);
int			*assign_index(int *stack_a, size_t stack_size);
void		push_small(int *stack_a, size_t stack_size);
void		push_big(int *stack_a, size_t stack_size);

/*A_MOVES*/
void		do_sa(int *stack_a);
void		do_pa(int *stack_a, int *stack_b, size_t stack_size);
void		do_ra(int *stack_a, size_t stack_size);
void		do_rra(int *stack_a, size_t stack_size);

/*B_MOVES*/
void		do_sb(int *stack_b);
void		do_pb(int *stack_a, int *stack_b, size_t stack_size);

/*TINY_SORT*/
void		tiny_sort(int *stack_a, int *stack_b, size_t stack_size);
void		sort_three(int *stack_a, size_t stack_size);

/*BIG_RADIX*/
void		use_stacks(int *stack_a, int *stack_b, size_t bit_i,
				size_t stack_size);
void		join_stacks(int *stack_a, int *stack_b, size_t size);
size_t		check_bits(int num_in_bits, size_t bit_i);

#endif
