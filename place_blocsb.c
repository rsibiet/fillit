/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_blocsb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:43:19 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 13:03:45 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		control_xb(char **res, int x[4], t_path *path, char **f_bls)
{
	if (res[x[1]][x[3]] == '.')
	{
		if (test_place(res, f_bls[path->path[x[0]][0]], x[3], x[1]) == 0)
		{
			if (path->path[x[0]][1] == 0)
			{
				path->path[x[0]][2] = x[1];
				path->path[x[0]][3] = x[3] + 1;
			}
			path->mem_index = x[0];
			add_bloc(res, f_bls[path->path[x[0]][0]], x[3], x[1]);
			if (x[0] == path->nb_bk - 1)
				return (0);
			x[0]++;
			x[1] = 0;
			x[2] = -1;
			x[3] = 0;
			if (path->path[x[0]][1] == 1 && res[path->path[x[0]][2]][0] != '\0')
			{
				x[1] = path->path[x[0]][2];
				x[3] = path->path[x[0]][3];
			}
		}
	}
	return (1);
}

int		init_indexb(t_path *path, int *y, int *z)
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

int		try_to_place(char **res, char **f_bls, t_path *path, int i)
{
	int		x[4];

	x[3] = i;
	x[0] = init_indexb(path, &x[1], &x[2]);
	while (res[x[1]][0] != '\0')
	{
		if (path->path[x[0]][1] == 1 && res[path->path[x[0]][2]][0] != '\0' &&
				x[2] == -1)
		{
			x[1] = path->path[x[0]][2];
			x[3] = path->path[x[0]][3];
		}
		x[2] = 0;
		while (res[x[1]][x[3]] != '\0')
		{
			if (control_xb(res, x, path, f_bls) == 0)
				return (0);
			x[3]++;
		}
		x[3] = 0;
		x[1]++;
	}
	path->mem_index = x[0];
	return (1);
}
