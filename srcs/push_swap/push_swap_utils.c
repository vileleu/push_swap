/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:56:33 by vico              #+#    #+#             */
/*   Updated: 2021/03/22 01:42:25 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_max(int *st, int m)
{
	int		max;
	int		sv;
	int		i;

	max = st[0];
	sv = 0;
	i = 0;
	while (++i < m)
	{
		if (st[i] > max)
		{
			max = st[i];
			sv = i;
		}
	}
	return (sv);
}

int		get_min(int *st, int m)
{
	int		min;
	int		sv;
	int		i;

	min = st[0];
	sv = 0;
	i = 0;
	while (++i < m)
	{
		if (st[i] < min)
		{
			min = st[i];
			sv = i;
		}
	}
	return (sv);
}

int		mediane(t_ps *ps, int *st, int m)
{
	int		*cpy;
	int		j;
	int		swap;

	if (!(cpy = malloc(sizeof(int) * m)))
		return (print_err(ERR_M));
	j = -1;
	while (++j < m)
		cpy[j] = st[j];
	j = -1;
	while (++j < m - 1)
	{
		if (cpy[j] > cpy[j + 1])
		{
			swap = cpy[j];
			cpy[j] = cpy[j + 1];
			cpy[j + 1] = swap;
			j = -1;
		}
	}
	ps->med = cpy[m / 5];
	free(cpy);
	return (1);
}
