/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:22:17 by jaimesanche       #+#    #+#             */
/*   Updated: 2023/01/07 14:16:08 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_words(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static char	*put_word(char const *s, char c)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_cpy_str(int i, char const *s, char c, char **res)
{
	res[i] = put_word(s, c);
	if (!res[i])
	{
		while (i > 0)
		{
			i--;
			free(res[i]);
		}
		free(res);
		return (NULL);
	}
	return (res[i]);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			res[i] = ft_cpy_str(i, s, c, res);
		while (*s && *s != c)
			s++;
		i++;
	}
	res[i] = 0;
	return (res);
}
