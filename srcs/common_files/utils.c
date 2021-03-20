/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:43:18 by vico              #+#    #+#             */
/*   Updated: 2021/03/19 23:08:45 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_check(t_c *check, int ma)
{
	check->line = NULL;
	check->ope = 0;
	check->sta = NULL;
	check->ma = ma;
	check->stb = NULL;
	check->mb = 0;
}

void	init_ps(t_ps *ps, int len)
{
	ps->pr = NULL;
	ps->pp = NULL;
	ps->sta = NULL;
	ps->ma = len;
	ps->stb = NULL;
	ps->mb = 0;
	ps->stp = NULL;
	ps->mp = 0;
	ps->med = 0;
	ps->x = 0;
	ps->st = NULL;
	ps->m = 0;
}

int		is_sort(int *sta, int max)
{
	int		i;

	i = -1;
	while (++i < max - 1)
	{
		if (sta[i] > sta[i + 1])
			return (0);
	}
	return (1);
}

int		create_plus(t_ps *ps)
{
	int		i;

	if (!(ps->stp = malloc(sizeof(int) * ps->ma)))
		return (print_err(ERR_M));
	i = -1;
	while (++i < ps->ma)
		ps->stp[i] = ps->sta[i];
	ps->mp = ps->ma;
	if (!(ps->st = malloc(sizeof(int) * ps->ma)))
		return (print_err(ERR_M));
	i = -1;
	while (++i < ps->ma)
		ps->st[i] = ps->sta[i];
	ps->m = ps->ma;
	return (1);
}
