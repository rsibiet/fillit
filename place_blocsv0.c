/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_blocsv0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:46:43 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 18:46:45 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		control_x(int *x, t_path *path, int *i, int *j)
{
	int		test_x;

	test_x = 0;
	if (*x == path->nb_bk - 1)
		test_x = 1;
	(*x)++;
	*i = 0;
	*j = 0;
	if (test_x == 1)
		return (0);
	return (1);
}

int		init_index(t_path *path)
{
	int		x;

	x = 0;
	while (path->path[x][0] == path->cp_path[x][0] && x < path->mem_index)
		x++;
	return (x);
}

int		try_to_placev0(char **res, char **f_bls, t_path *path, int i)
{
	int		x[2];

	x[0] = init_index(path);
	x[1] = 0;
	while (res[x[1]][0] != '\0')
	{
		while (res[x[1]][i] != '\0')
		{
			if (res[x[1]][i] == '.')
			{
				if (test_place(res, f_bls[path->path[x[0]][0]], i, x[1]) == 0)
				{
					path->mem_index = x[0];
					add_bloc(res, f_bls[path->path[x[0]][0]], i, x[1]);
					if (control_x(&x[0], path, &i, &x[1]) == 0)
						return (0);
				}
			}
			i++;
		}
		i = 0;
		x[1]++;
	}
	path->mem_index = x[0];
	return (1);
}

void	clean_resv0(char **res, t_path *path, int i)
{
	int		c;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (i < path->nb_bk)
	{
		while (path->path[i][0] == path->cp_path[i][0] && j == 0)
			i++;
		c = path->cp_path[i][0] + 'A';
		j = 0;
		while (res[j][0] != '\0')
		{
			while (res[j][k] != '\0')
			{
				if (res[j][k] == c)
					res[j][k] = '.';
				k++;
			}
			k = 0;
			j++;
		}
		i++;
	}
}

int		ft_placev0(char **res, char **f_bls, t_path *path, int i)
{
	if (res[0][0] != '.' || res[0][1] != '.' || res[0][2] != '.')
		clean_resv0(res, path, i);
	if (try_to_placev0(res, f_bls, path, i) == 1)
	{
		while (i < path->nb_bk)
		{
			path->cp_path[i][0] = path->path[i][0];
			i++;
		}
		return (1);
	}
	return (0);
}
