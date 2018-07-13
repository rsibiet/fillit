/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:32:33 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 15:35:44 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cur1;
	char	*cur2;

	cur1 = (char *)dst;
	cur2 = (char *)src;
	i = 0;
	while (i < n)
	{
		cur1[i] = cur2[i];
		i++;
	}
	return (dst);
}
