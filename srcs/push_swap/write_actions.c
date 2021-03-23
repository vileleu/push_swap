/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:44:56 by vico              #+#    #+#             */
/*   Updated: 2021/03/23 20:51:13 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		replace_print(char **prt, char *act, int *beg, int *len)
{
	char	*new;
	char	*tmp;
	int		i;

	if (!(tmp = malloc(sizeof(char) * (*beg + 1))))
		return (print_err(ERR_M));
	i = -1;
	while (++i < *beg)
		tmp[i] = (*prt)[i];
	tmp[i] = '\0';
	if (!(tmp = ft_strjoin(tmp, act)))
		return (print_free_err(ERR_M, tmp));
	if (!(new = ft_strdup(*prt + *beg + ft_strlen(act) * 2)))
		return (print_free_err(ERR_M, tmp));
	free(*prt);
	if (!(*prt = ft_strjoin(tmp, new)))
	{
		free(new);
		return (print_free_err(ERR_M, tmp));
	}
	free(new);
	*len = ft_strlen(*prt);
	*beg = *beg + ft_strlen(act);
	return (1);
}

int		cut_print(char **prt, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (i >= 0 && !ft_strncmp(*prt + i, "sa\nsb\n", 6) && \
		!replace_print(prt, "ss\n", &i, &len))
			return (0);
		else if (i >= 0 && !ft_strncmp(*prt + i, "sb\nsa\n", 6) && \
		!replace_print(prt, "ss\n", &i, &len))
			return (0);
		else if (i >= 0 && !ft_strncmp(*prt + i, "ra\nrb\n", 6) && (i == 0 \
		|| (*prt)[i - 1] != 'r') && !replace_print(prt, "rr\n", &i, &len))
			return (0);
		else if (i >= 0 && !ft_strncmp(*prt + i, "rb\nra\n", 6) && (i == 0 \
		|| (*prt)[i - 1] != 'r') && !replace_print(prt, "rr\n", &i, &len))
			return (0);
		else if (i >= 0 && !ft_strncmp(*prt + i, "rra\nrrb\n", 8) && \
		!replace_print(prt, "rrr\n", &i, &len))
			return (0);
		else if (i >= 0 && !ft_strncmp(*prt + i, "rrb\nrra\n", 8) && \
		!replace_print(prt, "rrr\n", &i, &len))
			return (0);
	}
	return (1);
}

int		write_print(char **prt, char *act)
{
	char	*cpy;

	if (!(cpy = ft_strdup(act)))
		return (print_err(ERR_M));
	if (!(cpy = ft_strjoin(cpy, "\n")))
		return (print_free_err(ERR_M, cpy));
	if (!(*prt))
	{
		if (!(*prt = ft_strdup(cpy)))
			return (print_free_err(ERR_M, cpy));
	}
	else
	{
		if (!(*prt = ft_strjoin(*prt, cpy)))
			return (print_free_err(ERR_M, cpy));
	}
	free(cpy);
	return (1);
}

int		actions_ps(t_ps *ps, char *act)
{
	if (!ft_strcmp(act, "sa") && write_print(&(ps->pr), act))
		return (swap(&(ps->sta), ps->ma));
	if (!ft_strcmp(act, "sb") && write_print(&(ps->pr), act))
		return (swap(&(ps->stb), ps->mb));
	if (!ft_strcmp(act, "ss") && write_print(&(ps->pr), act))
		return (swap_d(&(ps->sta), ps->ma, &(ps->stb), ps->mb));
	if (!ft_strcmp(act, "pa") && write_print(&(ps->pr), act))
		return (push(&(ps->sta), &(ps->ma), &(ps->stb), &(ps->mb)));
	if (!ft_strcmp(act, "pb") && write_print(&(ps->pr), act))
		return (push(&(ps->stb), &(ps->mb), &(ps->sta), &(ps->ma)));
	if (!ft_strcmp(act, "ra") && write_print(&(ps->pr), act))
		return (rotation(&(ps->sta), ps->ma));
	if (!ft_strcmp(act, "rb") && write_print(&(ps->pr), act))
		return (rotation(&(ps->stb), ps->mb));
	if (!ft_strcmp(act, "rr") && write_print(&(ps->pr), act))
		return (rotation_d(&(ps->sta), ps->ma, &(ps->stb), ps->mb));
	if (!ft_strcmp(act, "rra") && write_print(&(ps->pr), act))
		return (rrotation(&(ps->sta), ps->ma));
	if (!ft_strcmp(act, "rrb") && write_print(&(ps->pr), act))
		return (rrotation(&(ps->stb), ps->mb));
	if (!ft_strcmp(act, "rrr") && write_print(&(ps->pr), act))
		return (rrotation_d(&(ps->sta), ps->ma, &(ps->stb), ps->mb));
	return (0);
}

int		actions_ps_p(t_ps *ps, char *act)
{
	if (!ft_strcmp(act, "sa") && write_print(&(ps->pp), act))
		return (swap(&(ps->stp), ps->mp));
	if (!ft_strcmp(act, "sb") && write_print(&(ps->pp), act))
		return (swap(&(ps->stb), ps->mb));
	if (!ft_strcmp(act, "ss") && write_print(&(ps->pp), act))
		return (swap_d(&(ps->stp), ps->mp, &(ps->stb), ps->mb));
	if (!ft_strcmp(act, "pa") && write_print(&(ps->pp), act))
		return (push(&(ps->stp), &(ps->mp), &(ps->stb), &(ps->mb)));
	if (!ft_strcmp(act, "pb") && write_print(&(ps->pp), act))
		return (push(&(ps->stb), &(ps->mb), &(ps->stp), &(ps->mp)));
	if (!ft_strcmp(act, "ra") && write_print(&(ps->pp), act))
		return (rotation(&(ps->stp), ps->mp));
	if (!ft_strcmp(act, "rb") && write_print(&(ps->pp), act))
		return (rotation(&(ps->stb), ps->mb));
	if (!ft_strcmp(act, "rr") && write_print(&(ps->pp), act))
		return (rotation_d(&(ps->stp), ps->mp, &(ps->stb), ps->mb));
	if (!ft_strcmp(act, "rra") && write_print(&(ps->pp), act))
		return (rrotation(&(ps->stp), ps->mp));
	if (!ft_strcmp(act, "rrb") && write_print(&(ps->pp), act))
		return (rrotation(&(ps->stb), ps->mb));
	if (!ft_strcmp(act, "rrr") && write_print(&(ps->pp), act))
		return (rrotation_d(&(ps->stp), ps->mp, &(ps->stb), ps->mb));
	return (0);
}
