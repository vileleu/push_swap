/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:22:20 by vico              #+#    #+#             */
/*   Updated: 2021/04/29 20:25:07 by vico             ###   ########.fr       */
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
			else if ((int)ft_strlen(av[i]) == 10 + j && \
			ft_strcmp(max + 1 - j, av[i]) < 0)
				return (-1);
		}
		else if (av[i][0] == '-' && !j++)
		{
			if ((int)ft_strlen(av[i]) > 10 + j)
				return (-1);
			else if ((int)ft_strlen(av[i]) == 10 + j && \
			ft_strcmp(min, av[i]) < 0)
				return (-1);
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
