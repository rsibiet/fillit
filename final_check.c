/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:18:21 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/21 20:58:52 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	cut_shape(char **tetris, char **f_bls, t_blocmin *bmin, int j)
{
	int i[5];

	i[0] = bmin->x_min;
	i[2] = j;
	i[3] = (bmin->x_max - bmin->x_min + 2) * (bmin->y_max - bmin->y_min + 1);
	i[1] = 0;
	i[4] = 0;
	f_bls[j] = (char *)malloc(sizeof(char) * i[3]);
	if (f_bls == NULL)
		return ;
	final_cut_shape(tetris, f_bls, bmin, i);
	f_bls[i[2]][i[1]] = '\0';
}

void	find_min(char **tetris, t_blocmin *bmin, int i, int j)
{
	int	tp;

	tp = 0;
	while (tetris[j][i] != '\0')
	{
		while ((tetris[j][i] < 'A' || tetris[j][i] > 'Z')
				&& tetris[j][i] != '\n' && tetris[j][i] != '\0')
			i++;
		if (tetris[j][i] >= 'A' && tetris[j][i] <= 'Z'
			&& bmin->x_min > (i - 5 * tp))
			bmin->x_min = (i - 5 * tp);
		if (tetris[j][i] >= 'A' && tetris[j][i] <= 'Z')
			bmin->nb++;
		if (tetris[j][i] == '\n' && bmin->nb == 0)
			bmin->y_min++;
		if (tetris[j][i] == '\n')
			tp++;
		i++;
	}
	bmin->nb = 0;
}

void	find_max(char **tetris, t_blocmin *bmin, int i, int j)
{
	int		tp;

	tp = 0;
	while (tetris[j][i] != '\0')
	{
		while ((tetris[j][i] < 'A' || tetris[j][i] > 'Z')
				&& tetris[j][i] != '\n' && tetris[j][i] != '\0')
			i++;
		if (tetris[j][i] >= 'A' && tetris[j][i] <= 'Z'
				&& bmin->x_max < (i - 5 * bmin->y_max))
			bmin->x_max = (i - 5 * bmin->y_max);
		if (tetris[j][i] >= 'A' && tetris[j][i] <= 'Z')
			bmin->nb++;
		if (tetris[j][i] == '\n' && bmin->nb == 4 && tp == 0)
			tp = 1;
		if (tetris[j][i] == '\n' && bmin->nb <= 4 && tp == 0)
			bmin->y_max++;
		i++;
	}
}

void	verificator(char **tetris, char **f_bls, int nb_bk)
{
	t_blocmin	bmin;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < nb_bk)
	{
		bmin.y_min = 0;
		bmin.x_min = 4;
		bmin.y_max = 0;
		bmin.x_max = 0;
		bmin.nb = 0;
		find_min(tetris, &bmin, i, j);
		find_max(tetris, &bmin, i, j);
		cut_shape(tetris, f_bls, &bmin, j);
		j++;
	}
	j = 0;
	init_res(f_bls, nb_bk, i);
}

void	create_tab(char *c, int nb)
{
	int			i;
	int			j;
	char		**tetris;
	char		**f_bls;
	int			nb_of_bls;

	i = 0;
	j = 0;
	nb_of_bls = 0;
	f_bls = (char **)malloc(sizeof(char *) * (nb + 1));
	tetris = (char **)malloc(sizeof(char *) * (nb + 1));
	if (f_bls == NULL || tetris == NULL)
		return ;
	while (nb_of_bls < nb)
	{
		tetris[j] = ft_strsub(c, i, 20);
		i = i + 21;
		j++;
		nb_of_bls++;
	}
	verificator(tetris, f_bls, nb_of_bls);
}
