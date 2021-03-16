/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:43:18 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 00:21:29 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_check(t_o *check, int ma)
{
	check->line = NULL;
	check->ope = 0;
	check->sta = NULL;
	check->ma = ma;
	check->stb = NULL;
	check->mb = 0;
}

int		is_sort(int *sta, int max)
{
	int		i;

	i = -1;
	while (++i < max - 1)
	{
		if (sta[i] > sta[i + 1])
			return (0);
	}
	return (1);
}
