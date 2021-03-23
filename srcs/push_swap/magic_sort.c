/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:10:54 by vico              #+#    #+#             */
/*   Updated: 2021/03/23 21:05:36 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		magic_rota(t_ps *ps, int *i, int *j, char *act)
{
	if (!ft_strcmp("ra", act))
	{
		while ((*i)--)
		{
			if (!(actions_ps(ps, act)))
				return (0);
		}
		*j = ps->ma;
	}
	else
	{
		while (*j < ps->ma)
		{
			if (!(actions_ps(ps, act)))
				return (0);
			(*j)++;
		}
		*i = 0;
	}
	return (1);
}

int		push_to_b(t_ps *ps, int max, int len, int i)
{
	int		j;

	j = ps->ma;
	while (ps->mb < len && ++i < ps->ma && --j > 0)
	{
		while (ps->mb < len && ps->sta[0] < max)
		{
			if (!(actions_ps(ps, "pb")))
				return (0);
			i = 1;
			j = ps->ma - 1;
		}
		if (ps->mb < len && ps->sta[i] < max)
		{
			if (!(magic_rota(ps, &i, &j, "ra")))
				return (0);
		}
		else if (ps->mb < len && ps->sta[j] < max)
		{
			if (!(magic_rota(ps, &i, &j, "rra")))
				return (0);
		}
	}
	return (1);
}

int		chunks(t_ps *ps, int *cpy, int chk)
{
	int		len;
	int		max;

	len = ps->ma;
	max = chk;
	while (max < len)
	{
		if (!(push_to_b(ps, cpy[max], max, 0)))
			return (0);
		if (max == len - 1)
			break ;
		max += chk;
		if (max >= len)
			max = len - 1;
	}
	free(cpy);
	if (!(push_higher(ps)))
		return (0);
	if (!cut_print(&(ps->pr), ft_strlen(ps->pr)))
		return (0);
	ft_putstr_fd(ps->pr, 1);
	free_ps(ps);
	return (1);
}

int		magic_sort(t_ps *ps)
{
	int		*cpy;
	int		j;
	int		swap;

	if (!(cpy = ft_intcpy(ps->sta, ps->ma)))
		return (0);
	j = -1;
	while (++j < ps->ma - 1)
	{
		if (cpy[j] > cpy[j + 1])
		{
			swap = cpy[j];
			cpy[j] = cpy[j + 1];
			cpy[j + 1] = swap;
			j = -1;
		}
	}
	if (ps->ma == 100)
		return (chunks(ps, cpy, 20));
	else
		return (chunks(ps, cpy, 47));
}
