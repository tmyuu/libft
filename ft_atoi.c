/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:01:38 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/12 20:07:14 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calculate_atoi(const char *s, int sign, int i)
{
	long	n;

	n = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		if ((n * 10 + (s[i] - '0')) < n)
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			else if (sign == 1)
				return ((int)LONG_MAX);
		}
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(n * sign));
}

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
		i++;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_calculate_atoi(s, sign, i));
}
