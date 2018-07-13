/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:42:07 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/30 11:44:44 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	size_t			len;
	size_t			end;
	unsigned int	st;
	char			*str;

	if (!s)
		return (NULL);
	st = 0;
	while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && s[st] != '\0')
		st++;
	if (s[st] == '\0')
		return (ft_strnew(1));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (st == 0 && end == ft_strlen(s) - 1)
		return (ft_strcpy(ft_strnew(ft_strlen(s)), s));
	len = ft_strlen(s) - st - (ft_strlen(s) - end - 1);
	return (str = ft_strsub(s, st, len));
}
