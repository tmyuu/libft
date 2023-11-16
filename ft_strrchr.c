/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:27:26 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/04 15:39:27 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (0 <= len)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		else if (len == 0)
			break ;
		len--;
	}
	if ((char)c == '\0')
		return ((char *)&s[len]);
	return (NULL);
}
