/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:20:06 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/28 18:50:57 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_point(char **res, int k, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		res[k][i] = '.';
		i++;
	}
	res[k][i] = '\0';
}

char	**init_tab_res(int size)
{
	char	**res;
	int		k;

	k = 0;
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		put_error();
	while (k < size)
	{
		res[k] = (char *)malloc(sizeof(char) * (size + 1));
		if (res[k] == NULL)
			put_error();
		res[k][size] = '\0';
		put_point(res, k, size);
		k++;
	}
	res[k] = (char *)malloc(sizeof(char) * 1);
	if (res[k] == NULL)
		put_error();
	res[k][0] = '\0';
	return (res);
}

int		res_fillit(char **res, char **f_bls, int nb_bk, int nb_bin)
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
		if (ft_place(res, f_bls, &path, i) == 1)
			next = path_finder(&path, i);
		else
			return (0);
	}
	return (1);
}

void	display_res(char **res)
{
	int i;

	i = 0;
	while (res[i][0] != '\0')
	{
		ft_putendl(res[i]);
		i++;
	}
}

void	init_res(char **f_bls, int nb_bk, int i)
{
	char	**res;
	int		size;
	int		nb_bin;

	i = 0;
	size = 0;
	nb_bin = 1;
	while (i <= (nb_bk - 2))
	{
		nb_bin *= 2;
		i++;
	}
	nb_bin += 2;
	while (size * size < nb_bk * 4)
		size++;
	res = init_tab_res(size);
	while (res_fillit(res, f_bls, nb_bk, nb_bin) != 0)
	{
		free(res);
		size++;
		res = init_tab_res(size);
	}
	retry_and_comp(res, nb_bin, f_bls, nb_bk);
}
