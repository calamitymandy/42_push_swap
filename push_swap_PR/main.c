/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:33:35 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/08 16:38:11 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* count how many numbers there is by initializing size at 1 and +1 each
time there is a blank space*/
int	stack_size(int argc, char **argv)
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

/* */
void	set_nums_at_index1(int *count_nums_a, int *count_nums_b, int argc)
{
	count_nums_a[0] = argc - 1;
	count_nums_a[1] = count_nums_a[0];
	count_nums_b = 0;
}

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;
	int		*count_nums_a;
	int		*count_nums_b;

	count_nums_a = (int *)malloc(2 * sizeof(int));
	count_nums_b = (int *)malloc(sizeof(int));
//check_params(argc, argv, count_nums_a, count_nums_b);
	set_nums_at_index1(count_nums_a, count_nums_b, argc);
	stack_a = (long *)malloc(sizeof(long) * stack_size(argc, argv));
	stack_b = (long *)malloc(sizeof(long) * stack_size(argc, argv));
}
