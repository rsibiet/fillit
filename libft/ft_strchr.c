/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:48:58 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 15:34:22 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int i;
	int t;

	t = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == t)
		return ((char *)&s[i]);
	return (NULL);
}
