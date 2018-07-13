/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddesnoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:39:45 by ddesnoye          #+#    #+#             */
/*   Updated: 2015/12/28 18:45:32 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_error(void)
{
	ft_putendl("error");
	exit(1);
}

void	ft_open_file(int fd)
{
	size_t		i;
	char		*c;
	char		file;

	i = 0;
	while (read(fd, &file, 1))
		i++;
	lseek(fd, -i, SEEK_END);
	c = ft_strnew(i);
	i = 0;
	while (read(fd, &file, 1))
	{
		c[i] = file;
		if (c[i] != '#' && c[i] != '.' && c[i] != '\n')
			put_error();
		i++;
	}
	c[i] = '\0';
	i = ft_check_file(c);
	ft_check_shape(c);
	ft_name_blocks(c);
	create_tab(c, i);
	free(c);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		put_error();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		put_error();
	ft_open_file(fd);
	close(fd);
	return (0);
}
