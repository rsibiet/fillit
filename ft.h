/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:34:17 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/29 14:56:49 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_params
{
	int			x_bloc;
	int			y_bloc;
	int			tetri_nb;
}				t_params;

typedef struct	s_path
{
	int			path[26][4];
	int			cp_path[26][2];
	int			nb_bk;
	int			nb_bin;
	int			mem_index;
	int			compt;
}				t_path;

typedef	struct	s_blocmin
{
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	int			nb;
}				t_blocmin;

/*
** Fonctions in main file
*/

void			ft_open_file(int fd);
void			put_error(void);

/*
** Fonctions in checkblocks file
*/

int				ft_check_file(char *c);
int				ft_check_blocks(t_params *par, char *c, int *i);
void			ft_name_blocks(char *c);
void			ft_check_shape(char *s);
int				ft_check_shape2(char *s, int i, int count, int x);

/*
** Fonctions in final_check file
*/

void			create_tab(char *c, int nb);
void			verificator(char **tetris, char **f_bls, int nb_bk);
void			find_max(char **tetris, t_blocmin *bmin, int i, int j);
void			find_min(char **tetris, t_blocmin *bmin, int i, int j);
void			cut_shape(char **tetris, char **f_bls, t_blocmin *bmin,
					int j);

/*
** Fonctions in end_of_check file
*/

void			final_cut_shape(char **tetris, char **f_bls, t_blocmin *bmin,
					int i[5]);

/*
** Fonctions in resolve_me file
*/

void			init_res(char **f_bls, int nb_bk, int i);
void			display_res(char **res);
int				res_fillit(char **res, char **f_bls, int size, int nb_bin);
char			**init_tab_res(int size);
void			put_point(char **res, int k, int size);

/*
** Fonctions in path_finder file
*/

int				path_finder(t_path *path, int i);
int				test_path(int i, t_path *path, int pos);
void			create_path(t_path *path, int *pos, int *memo_pos);
void			first_path(t_path *path, int i);

/*
** Fonctions in path_finderb file
*/

int				control_path(t_path *path, int i);
void			init_path(t_path *path, int nb_bk, int nb_bin, int i);

/*
** Fonctions in path_bis file
*/

int				path_bis_finder(t_path *path);
int				first_path_bis(t_path *path);

/*
** Fonctions in place_blocs file
*/

int				ft_place(char **res, char **f_bls, t_path *path, int i);
void			clean_res(char **res, t_path *path, int i);
int				test_place(char **res, char *bloc, int i, int j);
void			add_bloc(char **res, char *bloc, int i, int j);
void			define_n5(char **res, char **res2, int n[5]);

/*
** Fonctions in place_blocsb file
*/

int				try_to_place(char **res, char **f_bls, t_path *path, int i);
int				init_indexb(t_path *path, int *y, int *z);
int				control_xb(char **res, int x[4], t_path *path, char **f_bls);

/*
** Fonctions in place_blocsv0 file
*/

int				ft_placev0(char **res, char **f_bls, t_path *path, int i);
void			clean_resv0(char **res, t_path *path, int i);
int				try_to_placev0(char **res, char **f_bls, t_path *path, int i);
int				init_index(t_path *path);
int				control_x(int *x, t_path *path, int *i, int *j);

/*
** Fonctions in place_blocsv1 file
*/

int				ft_placev1(char **res, char **f_bls, t_path *path, int i);
int				try_to_placev1(char **res, char **f_bls, t_path *path, int i);
int				init_indexv1(t_path *path, int *y, int *z);
int				control_xv1(char **res, int x[4], t_path *path, char **f_bls);

/*
** Fonctions in resolve_again file
*/

void			retry_and_comp(char **res, int nb_bin, char **f_bls, int nb_bk);
int				res_fillitv0(char **res, char **f_bls, int nb_bk, int i);
int				res_fillitv1(char **res, char **f_bls, int nb_bk, int nb_bin);
void			find_the_best(char **res, char **res2, char **res3);
void			define_n(char **res, char **res2, int n[5]);

/*
** Fonctions in finish_him file
*/

void			finish_him(char **res, char **res2, int n[5]);
int				define_n1(char **res, char **res2, int n[5]);
int				define_n2(char **res, char **res2, int n[5]);
int				define_n3(char **res, char **res2, int n[5], int a);
int				define_n4(char **res, char **res2, int n[5], int a);
#endif
