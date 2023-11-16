/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:30:27 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/10 12:01:18 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_itoa(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		count++;
		n = -n;
	}
	else if (n == 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ptr;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_count_itoa(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	else if (n == 0)
		ptr[n] = '0';
	while (n)
	{
		ptr[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
