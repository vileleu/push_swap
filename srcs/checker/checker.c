/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:32:55 by vico              #+#    #+#             */
/*   Updated: 2021/03/22 01:48:56 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		save_line(t_c *check, char *line)
{
	t_list	*tmp;
	char	*cpy;

	tmp = NULL;
	if (!(cpy = ft_strdup(line)))
		return (print_err(ERR_M));
	if (!(check->ope))
	{
		if (!(check->line = ft_lstnew(cpy)))
			return (print_free_err(ERR_M, cpy));
	}
	else
	{
		if (!(tmp = ft_lstnew(cpy)))
			return (print_free_err(ERR_M, cpy));
		ft_lstadd_back(&(check->line), tmp);
	}
	(check->ope)++;
	return (1);
}

int		actions_c(t_c *c, t_list *tmp)
{
	if (!ft_strcmp(tmp->content, "sa"))
		return (swap(&(c->sta), c->ma));
	if (!ft_strcmp(tmp->content, "sb"))
		return (swap(&(c->stb), c->mb));
	if (!ft_strcmp(tmp->content, "ss"))
		return (swap_d(&(c->sta), c->ma, &(c->stb), c->mb));
	if (!ft_strcmp(tmp->content, "pa"))
		return (push(&(c->sta), &(c->ma), &(c->stb), &(c->mb)));
	if (!ft_strcmp(tmp->content, "pb"))
		return (push(&(c->stb), &(c->mb), &(c->sta), &(c->ma)));
	if (!ft_strcmp(tmp->content, "ra"))
		return (rotation(&(c->sta), c->ma));
	if (!ft_strcmp(tmp->content, "rb"))
		return (rotation(&(c->stb), c->mb));
	if (!ft_strcmp(tmp->content, "rr"))
		return (rotation_d(&(c->sta), c->ma, &(c->stb), c->mb));
	if (!ft_strcmp(tmp->content, "rra"))
		return (rrotation(&(c->sta), c->ma));
	if (!ft_strcmp(tmp->content, "rrb"))
		return (rrotation(&(c->stb), c->mb));
	if (!ft_strcmp(tmp->content, "rrr"))
		return (rrotation_d(&(c->sta), c->ma, &(c->stb), c->mb));
	return (-1);
}

int		loop_c(t_c *c)
{
	t_list	*tmp;
	char	*line;
	int		ret;

	ret = 1;
	while (ret)
	{
		if ((ret = get_next_line(0, &line)) == -1)
			return (print_err(ERR_M));
		if ((ret || (!ret && ft_strcmp(line, ""))) && !(save_line(c, line)))
			return (print_free_err(ERR_M, line));
		free(line);
	}
	tmp = c->line;
	while (tmp)
	{
		if (!(ret = actions_c(c, tmp)))
			return (print_err(ERR_M));
		if (ret == -1)
			return (print_err(ERR));
		tmp = tmp->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_c		check;

	if (ac == 1)
		return (0);
	init_check(&check, ac - 1);
	if (!(parsing_c(&check, av)))
		return (0);
	if (!(loop_c(&check)))
		return (free_check(&check));
	ft_putnbr_fd(check.ope, 1);
	ft_putstr_fd(" operations\n", 1);
	if (is_sort(check.sta, check.ma) && !check.stb && !check.mb)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (free_check(&check));
}
