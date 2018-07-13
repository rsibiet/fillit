/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:04:07 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 15:36:52 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cur1;
	unsigned char	*cur2;
	unsigned char	y;

	i = 0;
	y = (unsigned char)c;
	if (dst != '\0' && src != '\0')
	{
		cur1 = (unsigned char *)dst;
		cur2 = (unsigned char *)src;
		while (i < n)
		{
			if (cur2[i] == y)
				return (&dst[i + 1]);
			cur1[i] = cur2[i];
			i++;
		}
	}
	return (NULL);
}
