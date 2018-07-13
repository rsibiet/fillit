/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:35:53 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/29 12:12:30 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		first_path_bis(t_path *path)
{
	if (path->compt == -2)
	{
		path->compt = 2;
		return (0);
	}
	return (1);
}

int		path_bis_finder(t_path *path)
{
	int		i;
	int		j;

	if (first_path_bis(path) == 0)
		return (0);
	while (path->compt < path->nb_bin)
	{
		j = 2;
		i = path->nb_bk - 2;
		while (i >= 0)
		{
			if (path->compt % j == 0)
			{
				if (path->path[i][1] == 0)
					path->path[i][1] = 1;
				else
					path->path[i][1] = 0;
			}
			j *= 2;
			i--;
		}
		path->compt += 2;
		return (0);
	}
	return (1);
}
