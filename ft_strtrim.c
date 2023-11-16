/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:42:56 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/12 20:11:57 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_forward_strtrim(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (s1[i] == set[j])
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	ft_reverse_strtrim(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (s1[len - 1] != set[j] && set[j] != '\0')
			j++;
		if (s1[len - 1] == set[j])
			len--;
		else
			break ;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = ft_forward_strtrim(s1, set, len);
	j = ft_reverse_strtrim(s1, set, len);
	return (ft_substr(s1, i, j - i));
}
