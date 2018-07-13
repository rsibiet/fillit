/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:28:52 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 17:20:37 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1;

	i = 0;
	while (dst[i] && i < size)
		i++;
	s1 = i;
	while (src[i - s1] && i < size - 1)
	{
		dst[i] = src[i - s1];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (s1 + ft_strlen(src));
}
