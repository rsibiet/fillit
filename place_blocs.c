/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_blocs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:24:11 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 14:35:05 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	add_bloc(char **res, char *bloc, int i, int j)
{
	int		a;
	int		memo_i;

	a = 0;
	while (bloc[a] == '.' && i - a > 0)
		a++;
	memo_i = i - a;
	while (bloc[a] != '\0')
	{
		while (bloc[a] != '\0' && bloc[a] != '\n')
		{
			if (bloc[a] != '.')
				res[j][i] = bloc[a];
			i++;
			a++;
		}
		if (bloc[a] != '\0')
			a++;
		j++;
		i = memo_i;
	}
}

int		test_place(char **res, char *bloc, int i, int j)
{
	int		a;
	int		memo_i;

	a = 0;
	while (bloc[a] == '.' && i - a > 0)
		a++;
	memo_i = i - a;
	while (bloc[a] != '\0')
	{
		while (bloc[a] != '\0' && bloc[a] != '\n')
		{
			if (res[j][i] != '\0' && (bloc[a] == '.' || res[j][i] == '.'))
				i++;
			else
				return (1);
			a++;
		}
		if (bloc[a] == '\0')
			return (0);
		a++;
		j++;
		i = memo_i;
	}
	return (0);
}

void	clean_res(char **res, t_path *path, int i)
{
	int		j;
	int		c[2];

	j = 0;
	c[1] = 0;
	while (i < path->nb_bk)
	{
		while (path->path[i][0] == path->cp_path[i][0] && j == 0 &&
				path->path[i][1] == path->cp_path[i][1])
			i++;
		c[0] = path->cp_path[i][0] + 'A';
		j = 0;
		while (res[j][0] != '\0')
		{
			while (res[j][c[1]] != '\0')
			{
				if (res[j][c[1]] == c[0])
					res[j][c[1]] = '.';
				c[1]++;
			}
			c[1] = 0;
			j++;
		}
		i++;
	}
}

int		ft_place(char **res, char **f_bls, t_path *path, int i)
{
	while (path_bis_finder(path) == 0)
	{
		if (res[0][0] != '.' || res[0][1] != '.' || res[0][2] != '.')
			clean_res(res, path, 0);
		if (try_to_place(res, f_bls, path, 0) == 0)
			return (0);
		while (i + 1 < path->nb_bk - 1)
		{
			path->cp_path[i + 1][1] = path->path[i + 1][1];
			i++;
		}
		i = 0;
	}
	while (i < path->nb_bk)
	{
		path->cp_path[i][0] = path->path[i][0];
		i++;
	}
	path->compt = -2;
	return (1);
}

void	define_n5(char **res, char **res2, int n[5])
{
	while (res[n[1]][n[0]] != '\0')
		n[0]++;
	while (res2[n[4]][n[2]] != '\0')
		n[2]++;
	if (n[0] > n[2])
		n[3] = 1;
	if (n[0] < n[2])
		n[3] = -1;
}
