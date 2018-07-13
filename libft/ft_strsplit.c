/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:29 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/30 11:48:27 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countwords(const char *s, char c)
{
	int words;
	int i;
	int test;

	i = 0;
	test = 0;
	words = 0;
	while (s[i])
	{
		if (test == 1 && s[i] == c)
			test = 0;
		if (test == 0 && s[i] != c && s[i])
		{
			test = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static int	ft_countletters(const char *s, int i, int c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		words;
	int		i;
	int		len;
	char	**save;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_countwords(s, c);
	if ((str = (char **)malloc(sizeof(*str) * (words + 1))) == NULL)
		return (NULL);
	save = str;
	while (s[i] != '\0')
	{
		(s[i] == c) ? i++ : 0;
		if (s[i] != c && s[i])
		{
			len = ft_countletters(s, i, c);
			*str++ = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	*str = 0;
	return (save);
}
