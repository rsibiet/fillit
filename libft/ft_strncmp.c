/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:15:56 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/26 15:36:19 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cur1;
	unsigned char	*cur2;

	cur1 = (unsigned char *)s1;
	cur2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cur1[i] && cur2[i] && cur1[i] == cur2[i] && (i + 1) < n)
		i++;
	return (cur1[i] - cur2[i]);
}
