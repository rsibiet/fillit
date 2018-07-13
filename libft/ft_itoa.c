/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:50:23 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/30 14:39:10 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_sizeint(int i)
{
	int size;

	size = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		size++;
		i /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		len;
	int		isneg;
	char	*result;
	int		i;

	isneg = 0;
	if (n == -2147483648 || n == 0)
		return ((n == 0) ? ft_strdup("0") : ft_strdup("-2147483648"));
	isneg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	len = ft_sizeint(n);
	if ((result = ft_strnew(len + isneg)) == NULL)
		return (NULL);
	i = len + isneg - 1;
	while (n)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (isneg)
		result[i] = '-';
	return (result);
}
