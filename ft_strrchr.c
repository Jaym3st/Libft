/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:35:41 by jaisanch          #+#    #+#             */
/*   Updated: 2022/10/18 15:23:34 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c > 255)
		c %= 256;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return (&((char *)s)[i]);
		}
		i--;
	}
	return (0);
}
