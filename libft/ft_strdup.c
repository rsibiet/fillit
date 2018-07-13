/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:09:18 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/30 17:01:28 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str1;

	if (s1)
	{
		str1 = ft_strnew(ft_strlen(s1));
		if (str1)
		{
			ft_strcpy(str1, s1);
			return (str1);
		}
	}
	return (NULL);
}
