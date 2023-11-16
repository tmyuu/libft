/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:25:05 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/02 15:54:43 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc1;
	unsigned char	uc2;
	unsigned int	i;

	uc1 = (unsigned char *)s;
	uc2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (uc1[i] == uc2)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
