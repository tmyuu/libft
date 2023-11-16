/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:59:45 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/10 18:29:39 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;

	if (!dst && !src)
		return (NULL);
	uc1 = (unsigned char *)dst;
	uc2 = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
		while (n-- > 0)
			uc1[n] = uc2[n];
	return (dst);
}
