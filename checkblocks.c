/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkblocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:39:34 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/12/16 19:35:10 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_checkshape2(char *s, int i, int count, int x)
{
	if (s[i] == '#' && count < 4 && (s[i + 1] == '#' || s[i + 5] == '#'))
	{
		if (x >= 14 && s[i + 1] != '#')
			put_error();
		return (1);
	}
	else if (s[i] == '#' && count == 2 && s[i + 4] == '#')
		return (1);
	else if (s[i] == '#' && count == 3 && ((s[i + 4] == '#' &&
					s[i - 1] == '#') || (s[i + 3] == '#' && s[i - 1] == '#')))
		return (1);
	return (0);
}

void	ft_check_shape(char *s)
{
	int i;
	int count;
	int x;

	count = 1;
	x = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_checkshape2(s, i, count, x) == 1)
			count++;
		else if (ft_checkshape2(s, i, count, x) == 1)
			count++;
		x++;
		i++;
		if (x == 20 && count != 4)
			put_error();
		else if (x == 20)
		{
			i++;
			count = 1;
			x = 0;
		}
	}
}

void	ft_name_blocks(char *c)
{
	int			i;
	int			line;
	char		name;

	i = 0;
	line = 0;
	name = 'A';
	while (c[i] != '\0')
	{
		if (c[i] == '#')
			c[i] = name;
		if (c[i] == '\n')
			line++;
		if (line == 4)
		{
			line = 0;
			name++;
			i++;
		}
		i++;
	}
}

int		ft_check_blocs(t_params *par, char *c, int *i)
{
	int nb_blocks;

	nb_blocks = 0;
	if (c[*i] != '\n' && c[*i] != '\0')
		put_error();
	else
	{
		par->y_bloc = 0;
		par->tetri_nb++;
		(*i)++;
	}
	if (par->tetri_nb > 26)
		put_error();
	nb_blocks = par->tetri_nb;
	return (nb_blocks);
}

int		ft_check_file(char *c)
{
	int			i;
	t_params	par;
	int			nb;

	par.y_bloc = 0;
	par.tetri_nb = 0;
	i = 0;
	while (c[i] != '\0')
	{
		par.x_bloc = 0;
		while (c[i] != '\n' && c[i] != '\0')
		{
			par.x_bloc++;
			i++;
		}
		if (par.x_bloc != 4)
			put_error();
		par.y_bloc++;
		i++;
		if (par.y_bloc == 4)
			nb = ft_check_blocs(&par, c, &i);
	}
	return (nb);
}
