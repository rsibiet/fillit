/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finderb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:12:22 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 19:14:32 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_path(t_path *path, int nb_bk, int nb_bin, int i)
{
	path->mem_index = 0;
	path->compt = -2;
	path->nb_bk = nb_bk;
	path->nb_bin = nb_bin;
	while (i < 26)
	{
		path->cp_path[i][0] = -1;
		path->cp_path[i][1] = 0;
		path->path[i][0] = -1;
		path->path[i][1] = 0;
		path->path[i][2] = 0;
		path->path[i][3] = 0;
		i++;
	}
}

int		control_path(t_path *path, int i)
{
	i = 0;
	while (i < path->nb_bk && path->path[i][0] == path->nb_bk - 1 - i)
		i++;
	if (i == path->nb_bk)
		return (1);
	return (0);
}
