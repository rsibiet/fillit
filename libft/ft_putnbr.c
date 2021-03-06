/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:06:45 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/11/27 11:55:23 by ddesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long m;

	m = n;
	if (m < 0)
	{
		m = -m;
		ft_putchar('-');
	}
	if (m >= 10)
	{
		ft_putnbr(m / 10);
		ft_putnbr(m % 10);
	}
	else
		ft_putchar(m + '0');
}
