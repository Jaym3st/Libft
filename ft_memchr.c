/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:39:58 by jaimesanche       #+#    #+#             */
/*   Updated: 2022/10/18 15:22:35 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	j;

	str = (unsigned char *)s;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == j)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (0);
}
