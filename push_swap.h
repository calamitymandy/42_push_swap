/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:39:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/09 19:18:21 by amdemuyn         ###   ########.fr       */
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
size_t      double_strlen(char	**str);
size_t         is_repeat(char **nums, size_t position);

#endif