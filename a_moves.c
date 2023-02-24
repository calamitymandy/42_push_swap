/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:32:48 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/24 16:33:09 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
* Output: sa(swap a)
* swap top 2 elements of stack a
*/
void    do_sa(int *stack_a)
{
    int temp;
    write (1, "sa\n", 3);
    temp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = temp;
}

/*
* Output: pa (push a)
* push tob element of stack b to top of stack a
*/


