/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:34:48 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 01:03:47 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_M "MALLOC FAILED\n"
# define ERR "ERROR\n"

# include <stdio.h>
# include "../srcs/libft/libft.h"

typedef struct	s_o
{
	t_list		*line;
	int			ope;
	int			*sta;
	int			ma;
	int			*stb;
	int			mb;
}				t_o;

/*
** fonctions erreurs
*/

int				print_err(char *msg);
int				free_err(char *s);
int				print_free_err(char *msg, char *s);
int				free_check(t_o *check);

/*
** fonctions parsing
*/

int				parsing(t_o *c, char **av);

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
** fonctions diverses
*/

void			init_check(t_o *check, int maxa);
int				is_sort(int *sta, int max);

#endif
