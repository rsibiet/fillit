/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_again.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:22:34 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/29 17:43:07 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	define_n(char **res, char **res2, int n[5])
{
	int	a;

	a = 0;
	while (n[3] == 0 && res[n[1]][0] != '\0' && res2[n[4]][n[2]] != '\0')
	{
		if (define_n1(res, res2, n) == 1)
			break ;
		if (define_n2(res, res2, n) == 1)
			break ;
		if (define_n3(res, res2, n, a) == 1)
			break ;
		if (define_n4(res, res2, n, a) == 1)
			break ;
		if (res[n[1]][n[0]] == res2[n[4]][n[2]])
			n[0]++;
		if (res[n[1]][n[0] - 1] == res2[n[4]][n[2]])
			n[2]++;
		else
			n[3] = res[n[1]][n[0]] - res2[n[4]][n[2]];
	}
	define_n5(res, res2, n);
}

void	find_the_best(char **res, char **res2, char **res3)
{
	int n[5];

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	n[4] = 0;
	define_n(res, res2, n);
	if (n[3] > 0)
		finish_him(res2, res3, n);
	else
		finish_him(res, res3, n);
	free(res);
	free(res2);
	free(res3);
}

int		res_fillitv1(char **res, char **f_bls, int nb_bk, int nb_bin)
{
	t_path		path;
	int			next;
	int			i;

	next = 0;
	i = 0;
	init_path(&path, nb_bk, nb_bin, i);
	first_path(&path, i);
	while (next != 1)
	{
		if (ft_placev1(res, f_bls, &path, i) == 1)
			next = path_finder(&path, i);
		else
			return (0);
	}
	return (1);
}

int		res_fillitv0(char **res, char **f_bls, int nb_bk, int i)
{
	t_path		path;
	int			next;

	next = 0;
	path.mem_index = 0;
	path.nb_bk = nb_bk;
	while (i < 26)
	{
		path.cp_path[i][0] = -1;
		path.path[i][0] = -1;
		i++;
	}
	i = 0;
	first_path(&path, i);
	while (next != 1)
	{
		if (ft_placev0(res, f_bls, &path, i) == 1)
			next = path_finder(&path, i);
		else
			return (0);
	}
	return (1);
}

void	retry_and_comp(char **res, int nb_bin, char **f_bls, int nb_bk)
{
	int		size[2];
	int		i;
	char	**res2;
	char	**res3;

	i = 0;
	size[0] = 0;
	while (size[0] * size[0] < nb_bk * 4)
		size[0]++;
	size[1] = size[0];
	res2 = init_tab_res(size[0]);
	res3 = init_tab_res(size[0]);
	while (res_fillitv0(res2, f_bls, nb_bk, i) != 0)
	{
		free(res2);
		size[0]++;
		res2 = init_tab_res(size[0]);
	}
	while (res_fillitv1(res3, f_bls, nb_bk, nb_bin) != 0)
	{
		free(res3);
		size[1]++;
		res3 = init_tab_res(size[1]);
	}
	find_the_best(res, res2, res3);
}
