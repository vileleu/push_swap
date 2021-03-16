/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:14:14 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 01:44:41 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		check_av(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && av[i][j] != '+' && av[i][j] != '-' \
			&& !ft_isdigit(av[i][j]))
				return (0);
			else if (j == 0 && (av[i][j] == '+' || av[i][j] == '-') \
			&& !av[i][j + 1])
				return (0);
			else if (j != 0 && !ft_isdigit(av[i][j]))
				return (0);
		}
	}
	if (i == 1)
		return (0);
	return (1);
}

int		max_min(char **av, char *max, char *min)
{
	int		i;
	int		j;

	i = -1;
	while (av[++i])
	{
		j = 0;
		if (ft_isdigit(av[i][0]) || (av[i][0] == '+' && !j++))
		{
			if ((int)ft_strlen(av[i]) > 10 + j)
				return (-1);
			else if ((int)ft_strlen(av[i]) == 10 + j)
				return (ft_strcmp(max + 1 - j, av[i]));
		}
		else if (av[i][0] == '-' && !j++)
		{
			if ((int)ft_strlen(av[i]) > 10 + j)
				return (-1);
			else if ((int)ft_strlen(av[i]) == 10 + j)
				return (ft_strcmp(min, av[i]));
		}
	}
	return (1);
}

int		*create_stack(char **av, int max)
{
	int		*sta;
	int		i;

	if (!(sta = malloc(sizeof(int) * max)))
		return (NULL);
	i = -1;
	while (++i < max)
		sta[i] = ft_atoi(av[i + 1]);
	return (sta);
}

int		no_duplicates(int *sta, int max)
{
	int		nb;
	int		i;
	int		j;

	i = -1;
	while (++i < max)
	{
		nb = sta[i];
		j = -1;
		while (++j < max)
		{
			if (i != j && nb == sta[j])
				return (0);
		}
	}
	return (1);
}

int		parsing(t_o *c, char **av)
{
	if (!(check_av(av)))
		return (print_err(ERR));
	if (max_min(av, "+2147483647", "-2147483648") < 0)
		return (print_err(ERR));
	if (!(c->sta = create_stack(av, c->ma)))
		return (print_err(ERR_M));
	if (!(no_duplicates(c->sta, c->ma)))
	{
		free(c->sta);
		return (print_err(ERR));
	}
	return (1);
}
