/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_him.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:27:27 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/29 17:40:05 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	finish_him(char **res, char **res2, int n[5])
{
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	n[4] = 0;
	define_n(res, res2, n);
	if (n[3] > 0)
		display_res(res2);
	else
		display_res(res);
}

int		define_n1(char **res, char **res2, int n[5])
{
	while (res[n[1]][n[0]] == res2[n[1]][n[0]] && res[n[1]][0] != '\0' &&
		res2[n[1]][0] != '\0')
	{
		while (res[n[1]][n[0]] != '\0' &&
			res[n[1]][n[0]] == res2[n[1]][n[0]])
			n[0]++;
		if (n[0] != 0 && res[n[1]][n[0]] == '\0')
		{
			n[1]++;
			n[0] = 0;
		}
	}
	if (res[n[1]][0] == '\0')
		return (1);
	else
	{
		n[4] = n[1];
		n[2] = n[0];
	}
	while (res[n[1]][n[0]] == '.')
		n[0]++;
	while (res2[n[4]][n[2]] == '.')
		n[2]++;
	return (0);
}

int		define_n2(char **res, char **res2, int n[5])
{
	if (res[n[1]][n[0]] == res2[n[4]][n[2]])
	{
		if (n[1] == n[4] && n[0] > n[2])
			n[3] = 1;
		else if (n[1] == n[4] && n[0] < n[2])
			n[3] = -1;
		else if (n[1] > n[4])
			n[3] = 1;
		else
			n[3] = -1;
		return (1);
	}
	if (res[n[1]][n[0]] == '\0' && res2[n[4]][n[2]] == '\0' && n[0] != 0
			&& n[2] != 0)
	{
		n[0] = 0;
		n[2] = 0;
		n[1]++;
		n[4]++;
		while (res[n[1]][n[0]] == '.')
			n[0]++;
		while (res2[n[4]][n[2]] == '.')
			n[2]++;
	}
	return (0);
}

int		define_n3(char **res, char **res2, int n[5], int a)
{
	if (res[n[1]][n[0]] == '\0' && n[0] != 0)
	{
		n[1]++;
		n[0] = 0;
		while (res[n[1] - 1][a] != '\0')
		{
			if (res[n[1]][n[0]] >= res2[n[4]][n[2]])
			{
				n[3] = 1;
				return (1);
			}
			if (res[n[1]][n[0]] == res[n[1] - 1][a])
			{
				n[0]++;
				a = 0;
			}
			a++;
		}
	}
	return (0);
}

int		define_n4(char **res, char **res2, int n[5], int a)
{
	if (res2[n[4]][n[2]] == '\0' && n[2] != 0)
	{
		if (res2[n[4]][n[2]] == '\0' && n[2] != 0)
		{
			n[4]++;
			n[2] = 0;
		}
		while (res2[n[4] - 1][a] != '\0')
		{
			if (res2[n[4]][n[2]] >= res[n[1]][n[0]])
			{
				n[3] = -1;
				return (1);
			}
			if (res2[n[4]][n[2]] == res2[n[4] - 1][a])
			{
				n[2]++;
				a = 0;
			}
			a++;
		}
	}
	return (0);
}
