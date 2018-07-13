/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:13:40 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/24 15:47:57 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int cur;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = i;
		cur = 0;
		while (s1[j] == s2[cur])
		{
			j++;
			cur++;
			if (s2[cur] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
