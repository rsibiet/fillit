/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:46:31 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/30 17:02:15 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *str;

	if (s1)
	{
		str = ft_strnew(ft_strlen(s1));
		if (str)
		{
			ft_strncpy(str, s1, n);
			return (str);
		}
	}
	return (NULL);
}
