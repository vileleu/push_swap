/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:36:46 by vico              #+#    #+#             */
/*   Updated: 2021/03/19 23:37:06 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		compare_bis_norme(t_ps *ps)
{
	free(ps->stp);
	free(ps->pp);
	ps->pp = NULL;
	if (!(ps->stp = ft_intcpy(ps->st, ps->m)))
		return (print_err(ERR_M));
	ps->mp = ps->m;
	return (1);
}

int		compare_bis(t_ps *ps, int cr, int cp)
{
	if (cp < cr)
	{
		free(ps->sta);
		if (!(ps->sta = ft_intcpy(ps->stp, ps->mp)))
			return (print_err(ERR_M));
		ps->ma = ps->mp;
		free(ps->pr);
		if (!(ps->pr = ft_strdup(ps->pp)))
			return (print_err(ERR_M));
		free(ps->pp);
		ps->pp = NULL;
		free(ps->stp);
		if (!(ps->stp = ft_intcpy(ps->st, ps->m)))
			return (print_err(ERR_M));
		ps->mp = ps->m;
	}
	else
		return (compare_bis_norme(ps));
	return (1);
}

int		compare(t_ps *ps)
{
	int		len;
	int		i;
	int		cr;
	int		cp;

	len = ft_strlen(ps->pr);
	i = -1;
	cr = 0;
	while (++i < len)
	{
		if ((ps->pr)[i] == '\n')
			cr++;
	}
	len = ft_strlen(ps->pp);
	i = -1;
	cp = 0;
	while (++i < len)
	{
		if ((ps->pp)[i] == '\n')
			cp++;
	}
	return (compare_bis(ps, cr, cp));
}
