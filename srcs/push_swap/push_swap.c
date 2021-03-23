/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:59:05 by vico              #+#    #+#             */
/*   Updated: 2021/03/23 21:05:08 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	other_test_bis(t_ps *ps, int *i, int *comp, int prev)
{
	if (ps->st[(*i) % ps->m] < ps->st[(*i + 1) % ps->m])
	{
		while (ps->st[(*i) % ps->m] < ps->st[(*i + 1) % ps->m])
		{
			(*comp)++;
			(*i)++;
			if ((*i % ps->m) == prev)
				break ;
		}
		(*comp)++;
	}
	else
		(*i)++;
}

int		other_test(t_ps *ps)
{
	int		ret;
	int		comp;
	int		i;
	int		prev;

	ret = 0;
	i = get_min(ps->st, ps->m);
	prev = i - 1;
	if (i == 0)
		prev = ps->m - 1;
	while (i % ps->m != prev)
	{
		comp = 0;
		other_test_bis(ps, &i, &comp, prev);
		if (comp > ret)
			ret = comp;
	}
	if (ret >= ps->mp / 2)
		return (1);
	return (0);
}

int		under_hundred(t_ps *ps)
{
	ps->x = ps->stp[get_min(ps->stp, ps->mp)];
	if (!(loop_ps_x(ps)))
		return (free_ps(ps));
	if (!cut_print(&(ps->pr), ft_strlen(ps->pr)) && \
	!cut_print(&(ps->pp), ft_strlen(ps->pp)))
		return (free_ps(ps));
	if (!(compare(ps)))
		return (free_ps(ps));
	ps->x = ps->stp[get_max(ps->stp, ps->mp)];
	if (!(loop_ps_x(ps)))
		return (free_ps(ps));
	if (!cut_print(&(ps->pp), ft_strlen(ps->pp)))
		return (free_ps(ps));
	if (!(compare(ps)))
		return (free_ps(ps));
	ft_putstr_fd(ps->pr, 1);
	return (free_ps(ps));
}

void	print_st(t_ps *ps, int *st, int m)
{
	int		i;

	i = -1;
	while (++i < ps->mb + m)
	{
		if (i < m)
			printf("st[%2d] = %5d |", i, st[i]);
		else
			printf("-------------- |");
		if (i < ps->mb)
			printf(" stb[%2d] = %5d\n", i, ps->stb[i]);
		else
			printf(" ---------------\n");
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	t_ps	ps;

	if (ac == 1)
		return (0);
	init_ps(&ps, ac - 1);
	if (!parsing_ps(&ps, av))
		return (0);
	if (ps.ma == 100 || ps.ma == 500)
		return (magic_sort(&ps));
	if (!create_plus(&ps))
		return (0);
	if (!(loop_ps(&ps)))
		return (free_ps(&ps));
	if (ac > 2 && other_test(&ps))
		return (under_hundred(&ps));
	if (!cut_print(&(ps.pr), ft_strlen(ps.pr)))
		return (free_ps(&ps));
	ft_putstr_fd(ps.pr, 1);
	return (free_ps(&ps));
}
