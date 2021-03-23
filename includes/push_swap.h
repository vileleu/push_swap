/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:34:48 by vico              #+#    #+#             */
/*   Updated: 2021/03/22 23:56:46 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_M "Malloc failed\n"
# define ERR "Error\n"

# include <stdio.h>
# include "../srcs/libft/libft.h"

typedef struct	s_c
{
	t_list		*line;
	int			ope;
	int			*sta;
	int			ma;
	int			*stb;
	int			mb;
}				t_c;

typedef struct	s_ps
{
	char		*pr;
	char		*pp;
	int			*sta;
	int			ma;
	int			*stb;
	int			mb;
	int			*stp;
	int			mp;
	int			*st;
	int			m;
	int			med;
	int			x;
}				t_ps;

/*
** fonctions erreurs
*/

int				print_err(char *msg);
int				free_err(char *s);
int				print_free_err(char *msg, char *s);

int				free_check(t_c *check);
int				free_ps(t_ps *ps);

/*
** fonctions parsing
*/

int				parsing_c(t_c *c, char **av);
int				parsing_ps(t_ps *ps, char **av);

int				check_av(char **av);
int				max_min(char **av, char *max, char *min);
int				*create_stack(char **av, int max);
int				no_duplicates(int *sta, int max);

/*
** fonctions manipulations des piles
*/

int				swap(int **stack, int max);
int				swap_d(int **sta, int maxa, int **stb, int maxb);

int				push(int **sta, int *maxa, int **stb, int *maxb);

int				rotation(int **stack, int max);
int				rotation_d(int **sta, int maxa, int **stb, int maxb);
int				rrotation(int **stack, int max);
int				rrotation_d(int **sta, int maxa, int **stb, int maxb);

/*
** fonctions algo
*/

int				sort_three(t_ps *ps, int *st, int m);
int				sort_four(t_ps *ps);
int				magic_sort(t_ps *ps);

/*
** algo #1
*/

int				loop_ps(t_ps *ps);
int				actions_ps(t_ps *ps, char *act);
int				mediane(t_ps *ps, int *st, int m);
int				which_rota(t_ps *ps, int med);
int				push_higher(t_ps *ps);
int				sort(t_ps *ps, int **st, int m, int n);

/*
** algo #2
*/

int				loop_ps_x(t_ps *ps);
int				actions_ps_p(t_ps *ps, char *act);
int				create_plus(t_ps *ps);

/*
** fonctions diverses
*/

void			init_check(t_c *check, int maxa);
void			init_ps(t_ps *ps, int len);

int				is_sort(int *sta, int max);
int				maybe_sort(int *st, int m);
int				get_max(int *st, int m);
int				get_min(int *st, int m);

int				compare(t_ps *ps);
int				cut_print(char **prt, int len);

void			print_st(t_ps *ps, int *st, int m);

#endif
