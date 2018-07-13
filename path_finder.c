/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:59:30 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 19:33:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	first_path(t_path *path, int i)
{
	int	pos;

	pos = 0;
	while (i < path->nb_bk)
	{
		path->path[pos][0] = i;
		path->cp_path[pos][0] = i;
		pos++;
		i++;
	}
}

void	create_path(t_path *path, int *pos, int *memo_pos)
{
	while (path->path[*pos][0] == path->nb_bk - 1 && *pos >= 0)
	{
		path->path[*pos][0] = 0;
		(*pos)--;
	}
	if (*pos >= 0)
		path->path[*pos][0]++;
	*memo_pos = *pos;
	if (*memo_pos < path->nb_bk - 1 && path->path[*memo_pos + 1][0] == 0)
	{
		(*memo_pos)++;
		while (*memo_pos < path->nb_bk - 1 && path->path[*memo_pos + 1][0]
			== 0)
		{
			(*memo_pos)++;
			path->path[*memo_pos][0] = path->path[*memo_pos - 1][0] + 1;
		}
	}
}

int		test_path(int i, t_path *path, int pos)
{
	while (i <= path->nb_bk)
	{
		if (i < path->nb_bk && path->path[pos][0] != path->path[i][0])
			i++;
		else if (i == path->nb_bk)
		{
			pos++;
			i = pos + 1;
		}
		else
			i = path->nb_bk + 1;
		if (i == path->nb_bk && pos == path->nb_bk - 1)
		{
			if (control_path(path, i) == 0)
				return (0);
			return (1);
		}
	}
	return (2);
}

int		path_finder(t_path *path, int i)
{
	int	pos;
	int	memo_pos;

	pos = 0;
	while (pos >= 0)
	{
		pos = path->nb_bk - 1;
		i = path->path[pos][0];
		if (i < path->nb_bk - 1)
		{
			i++;
			path->path[pos][0] = i;
		}
		else
			create_path(path, &pos, &memo_pos);
		pos = 0;
		i = test_path(1, path, pos);
		if (i == 0)
			return (0);
		else if (i == 1)
			return (1);
	}
	return (1);
}
