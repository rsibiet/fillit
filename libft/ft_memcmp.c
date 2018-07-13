/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:11:49 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 14:32:26 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cur1;
	unsigned char	*cur2;

	i = 0;
	cur1 = (unsigned char *)s1;
	cur2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cur1[i] != cur2[i])
			return (cur1[i] - cur2[i]);
		i++;
	}
	return (0);
}
