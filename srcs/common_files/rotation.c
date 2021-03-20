/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:29:10 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 01:21:16 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		rotation(int **stack, int max)
{
	int		save;
	int		i;

	if (max == 0 || max == 1)
		return (1);
	save = (*stack)[0];
	i = -1;
	while (++i < max - 1)
		(*stack)[i] = (*stack)[i + 1];
	(*stack)[i] = save;
	return (1);
}

int		rotation_d(int **sta, int maxa, int **stb, int maxb)
{
	rotation(sta, maxa);
	rotation(stb, maxb);
	return (1);
}

int		rrotation(int **stack, int max)
{
	int		save;

	if (max == 0 || max == 1)
		return (1);
	save = (*stack)[max - 1];
	while (--max > 0)
		(*stack)[max] = (*stack)[max - 1];
	(*stack)[0] = save;
	return (1);
}

int		rrotation_d(int **sta, int maxa, int **stb, int maxb)
{
	rrotation(sta, maxa);
	rrotation(stb, maxb);
	return (1);
}
