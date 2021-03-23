/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:41:40 by vico              #+#    #+#             */
/*   Updated: 2021/03/23 20:44:11 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		which_higher(int *st, int m)
{
	int		high;
	int		pos;
	int		i;

	i = 0;
	high = st[i];
	pos = i;
	while (i < m)
	{
		if (st[i] > high)
		{
			high = st[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		close_high(t_ps *ps, int high, char **act)
{
	int		up;
	int		down;
	int		h_cpy;

	up = 0;
	down = 0;
	h_cpy = high;
	while (h_cpy-- > 0)
		up++;
	while (high++ < ps->mb)
		down++;
	if (up <= down)
	{
		*act = "rb";
		return (up);
	}
	else
	{
		*act = "rrb";
		return (down);
	}
}

int		push_higher(t_ps *ps)
{
	char	*act;
	int		high;

	while (ps->mb)
	{
		high = which_higher(ps->stb, ps->mb);
		high = close_high(ps, high, &act);
		while (high > 0)
		{
			if (!(actions_ps(ps, act)))
				return (0);
			high--;
		}
		if (!(actions_ps(ps, "pa")))
			return (0);
	}
	return (1);
}
