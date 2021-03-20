/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:35:08 by vico              #+#    #+#             */
/*   Updated: 2021/03/20 17:26:03 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		can_sa(t_ps *ps, int i, int n)
{
	if (n)
	{
		if (ps->stp[i] != ps->x && ps->stp[i + 1] != ps->x)
		{
			if (i == 0 && ps->stp[i] > ps->stp[i + 1])
				return (1);
			else if (ps->stp[i] > ps->stp[i + 1])
				return (i);
		}
	}
	else
	{
		if (i == 0 && ps->stp[i] != ps->x && ps->stp[ps->mp - 1] != ps->x)
		{
			if (ps->stp[i] < ps->stp[ps->mp - 1])
				return (1);
		}
		else if (i != 0 && ps->stp[i] != ps->x && ps->stp[i - 1] != ps->x)
		{
			if (ps->stp[i] < ps->stp[i - 1])
				return (ps->mp - i + 1);
		}
	}
	return (0);
}

int		find_rota_x(t_ps *ps, char **act)
{
	int		beg;
	int		end;
	int		ret;

	beg = 0;
	end = 1;
	*act = "";
	while (++beg < ps->mp - 1 && --end >= 0)
	{
		if ((ret = can_sa(ps, beg, 1)) > 0)
		{
			*act = "ra";
			return (ret);
		}
		else if ((ret = can_sa(ps, end, 0)) > 0)
		{
			*act = "rra";
			return (ret);
		}
		if (end == 0)
			end = ps->mp;
	}
	return (0);
}

int		loop_ps_x(t_ps *ps)
{
	char	*act;
	int		i;

	if (ps->stp[0] > ps->stp[1] && !actions_ps_p(ps, "sa"))
		return (0);
	while (!maybe_sort(ps->stp, ps->mp))
	{
		i = find_rota_x(ps, &act);
		while (i--)
		{
			if (!(actions_ps_p(ps, act)))
				return (0);
		}
		if (can_sa(ps, 0, 1) && !actions_ps_p(ps, "sa"))
			return (0);
	}
	if (!sort(ps, &(ps->stp), ps->mp, 1))
		return (0);
	return (1);
}
