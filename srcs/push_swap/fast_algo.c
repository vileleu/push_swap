/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:45:11 by vico              #+#    #+#             */
/*   Updated: 2021/03/19 23:14:29 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		sort(t_ps *ps, int **st, int m, int n)
{
	char	*act;
	int		min;

	if (!maybe_sort(*st, m))
		return (1);
	min = get_min(*st, m);
	act = "ra";
	if (min > m - min)
	{
		act = "rra";
		min = m - min;
	}
	while (min--)
	{
		if (n && !actions_ps_p(ps, act))
			return (0);
		else if (!n && !actions_ps(ps, act))
			return (0);
	}
	return (1);
}

int		maybe_sort(int *st, int m)
{
	int		ind;
	int		end;

	ind = get_min(st, m);
	end = ind - 1;
	if (ind == 0)
		end = m - 1;
	while (ind != end)
	{
		if (ind == m - 1)
		{
			if (st[ind] > st[0])
				return (0);
			ind = -1;
		}
		else if (st[ind] > st[ind + 1])
			return (0);
		ind++;
	}
	return (1);
}

int		sort_three(t_ps *ps, int *st, int m)
{
	int		min;
	int		max;
	int		i;

	min = st[0];
	max = st[0];
	i = -1;
	while (++i < m)
	{
		if (st[i] < min)
			min = st[i];
		if (st[i] > max)
			max = st[i];
	}
	if (st[1] == min && st[2] == max)
		return (actions_ps(ps, "sa"));
	else if (st[0] == max && st[2] == min && actions_ps(ps, "sa"))
		return (actions_ps(ps, "rra"));
	else if (st[0] == max && st[1] == min)
		return (actions_ps(ps, "ra"));
	else if (st[0] == min && st[1] == max && actions_ps(ps, "sa"))
		return (actions_ps(ps, "ra"));
	else if (st[1] == max && st[2] == min)
		return (actions_ps(ps, "rra"));
	return (0);
}
