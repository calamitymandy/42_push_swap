/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:43:57 by amdemuyn          #+#    #+#             */
/*   Updated: 2023/02/09 19:20:02 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nums(const char *str, char c)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			nums++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (nums);
		}
		i++;
	}
	return (nums);
}

static char	*nums_sep(const char *str, int start, int end)
{
	char	*nums;
	int		i;

	i = 0;
	nums = malloc(sizeof(char) * (end - start +1));
	while (start < end)
		nums[i++] = str[start++];
	nums[i] = '\0';
	return (nums);
}

char	*ft_splat(size_t i, const char	*s, char c, char **split)
{
	size_t	j;
	int		index;

	j = 0;
	index = -1;
	while (i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && index >= 0)
		{
			split[j++] = nums_sep(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split[j]);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_nums(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	ft_splat(i, s, c, split);
	return (split);
}
