/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_blocsv1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:54:36 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 14:42:23 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		control_xv1(char **res, int x[4], t_path *path, char **f_bls)
{
	if (res[x[1]][x[3]] == '.')
	{
		if (test_place(res, f_bls[path->path[x[0]][0]], x[3], x[1]) == 0)
		{
			if (path->path[x[0]][1] == 0)
				path->path[x[0]][2] = x[1] + 1;
			path->mem_index = x[0];
			add_bloc(res, f_bls[path->path[x[0]][0]], x[3], x[1]);
			if (x[0] == path->nb_bk - 1)
				return (0);
			x[0]++;
			x[1] = 0;
			if (path->path[x[0] - 1][2] > 1)
				x[1] = path->path[x[0] - 1][2] - 2;
			if (x[1] < 0)
				x[1] = 0;
			x[2] = -1;
			if (path->path[x[0]][1] == 1 && res[path->path[x[0]][2]][0] != '\0')
				x[1] = path->path[x[0]][2];
			x[3] = 0;
		}
	}
	return (1);
}

int		init_indexv1(t_path *path, int *y, int *z)
{
	int		x;

	x = 0;
	*y = 0;
	*z = -1;
	while (path->path[x][0] == path->cp_path[x][0] &&
		x < path->mem_index && path->path[x][1] == path->cp_path[x][1])
		x++;
	if (x > 0)
	{
		*y = path->path[x - 1][2] - 2;
		if (*y < 0)
			*y = 0;
	}
	return (x);
}

int		try_to_placev1(char **res, char **f_bls, t_path *path, int i)
{
	int		x[4];

	x[3] = i;
	x[0] = init_indexv1(path, &x[1], &x[2]);
	while (res[x[1]][0] != '\0')
	{
		if (path->path[x[0]][1] == 1 && res[path->path[x[0]][2]][0] != '\0' &&
				x[2] == -1)
			x[1] = path->path[x[0]][2];
		x[2] = 0;
		while (res[x[1]][x[3]] != '\0')
		{
			if (control_xv1(res, x, path, f_bls) == 0)
				return (0);
			x[3]++;
		}
		x[3] = 0;
		x[1]++;
	}
	path->mem_index = x[0];
	return (1);
}

int		ft_placev1(char **res, char **f_bls, t_path *path, int i)
{
	while (path_bis_finder(path) == 0)
	{
		if (res[0][0] != '.' || res[0][1] != '.' || res[0][2] != '.')
			clean_res(res, path, 0);
		if (try_to_placev1(res, f_bls, path, 0) == 0)
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
