/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:25:40 by vico              #+#    #+#             */
/*   Updated: 2021/03/22 22:38:37 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		find_rota(t_ps *ps, char *dir, int *i, int *j)
{
	if (!ft_strcmp(dir, "ra"))
	{
		while (*i > 0)
		{
			if (!(actions_ps(ps, dir)))
				return (0);
			(*i)--;
		}
		*j = ps->ma;
	}
	else
	{
		while (*j < ps->ma)
		{
			if (!(actions_ps(ps, dir)))
				return (0);
			(*j)++;
		}
		*i = 0;
	}
	return (1);
}

int		which_rota(t_ps *ps, int med)
{
	int		i;
	int		j;

	i = 0;
	j = ps->ma;
	while (ps->ma > 2 && ++i < ps->ma && --j > 0)
	{
		while (ps->ma > 2 && i == 1 && ps->sta[0] < med)
		{
			if (!(actions_ps(ps, "pb")))
				return (0);
			j = ps->ma - 1;
		}
		if (ps->ma > 2 && ps->sta[i] < med)
		{
			if (!(find_rota(ps, "ra", &i, &j)))
				return (0);
		}
		else if (ps->ma > 2 && ps->sta[j] < med)
		{
			if (!(find_rota(ps, "rra", &i, &j)))
				return (0);
		}
	}
	return (1);
}

int		loop_ps(t_ps *ps)
{
	int		ret;

	if (maybe_sort(ps->sta, ps->ma))
		return (sort(ps, &(ps->sta), ps->ma, 0));
	if (ps->ma == 2 && !is_sort(ps->sta, ps->ma))
		return (actions_ps(ps, "sa"));
	else if (ps->ma == 3)
		return (sort_three(ps, ps->sta, ps->ma));
	if (ps->sta[0] > ps->sta[1] && !actions_ps(ps, "sa"))
		return (0);
	ret = 1;
	while (ret == 1 && ps->ma > 2)
	{
		if (!(mediane(ps, ps->sta, ps->ma)))
			return (0);
		if (!(ret = which_rota(ps, ps->med)))
			return (0);
	}
	if (ps->ma == 2 && !is_sort(ps->sta, ps->ma) && !actions_ps(ps, "sa"))
		return (0);
	if (!(push_higher(ps)))
		return (0);
	return (1);
}
