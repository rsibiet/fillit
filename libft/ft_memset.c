/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:04:45 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/24 17:09:08 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;
	size_t			i;

	i = 0;
	cur = (unsigned char *)b;
	while (i < len)
	{
		cur[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
