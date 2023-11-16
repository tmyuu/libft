/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:23:50 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/10 11:03:18 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	uc1 = (unsigned char *)dst;
	uc2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		uc1[i] = uc2[i];
		i++;
	}
	return (dst);
}
