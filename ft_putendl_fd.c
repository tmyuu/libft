/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:56 by ymatsui           #+#    #+#             */
/*   Updated: 2023/11/12 19:59:17 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	if (s)
	{
		while (*s)
		{
			write(fd, s, sizeof(*s));
			s++;
		}
		write(fd, &c, sizeof(c));
	}
	else
		return ;
}
