/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:08:18 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/02 15:55:14 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc1;
	unsigned char	uc2;
	unsigned int	i;

	uc1 = (unsigned char *)b;
	uc2 = (unsigned char)c;
	i = 0;
	while (i < len)
		uc1[i++] = uc2;
	return (b);
}
