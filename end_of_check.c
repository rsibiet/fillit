/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:50:49 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/21 20:56:00 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	final_cut_shape(char **tetris, char **f_bls, t_blocmin *bmin, int i[5])
{
	while (i[0] <= (bmin->y_max * 5 + bmin->x_max))
	{
		if (i[0] >= bmin->x_min + 5 * i[4] && i[0] <= bmin->y_max * 5 +
			bmin->x_max && i[4] >= bmin->y_min && i[0]
			<= bmin->x_max + 5 * i[4])
		{
			f_bls[i[2]][i[1]] = tetris[i[2]][i[0]];
			i[1]++;
		}
		if (tetris[i[2]][i[0]] == '\n' && i[1] != 0)
		{
			f_bls[i[2]][i[1]] = '\n';
			i[4]++;
			i[1]++;
		}
		else if (tetris[i[2]][i[0]] == '\n')
			i[4]++;
		i[0]++;
	}
}
