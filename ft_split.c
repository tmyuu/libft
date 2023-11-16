/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:13:53 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/10 18:47:16 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_split(char const *s, char c)
{
	int	count;
	int	check;

	count = 0;
	check = 1;
	while (*s)
	{
		if (*s == c)
			check = 1;
		else if (check)
		{
			check = 0;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**ft_free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

static char	**ft_extract_split(char const *s, char c, char **ptr, int i)
{
	int	start;
	int	end;

	start = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			ptr[i] = ft_substr(s, start, end - start);
			if (!ptr[i])
				return (ft_free_split(ptr));
			i++;
		}
		if (s[end])
			start = end + 1;
		else
			break ;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_count_split(s, c) + 1));
	if (!ptr)
		return (NULL);
	return (ft_extract_split(s, c, ptr, 0));
}
