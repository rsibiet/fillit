/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:28:07 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 15:35:13 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j])
		{
			if (i + j == n)
				break ;
			j++;
		}
		if (!s2[j])
			return ((char *)&s1[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
