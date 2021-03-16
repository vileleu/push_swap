/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:01:04 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 01:40:19 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		swap(int **stack, int max)
{
	int		swap;

	if (max < 2)
		return (1);
	swap = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = swap;
	return (1);
}

int		swap_d(int **sta, int maxa, int **stb, int maxb)
{
	swap(sta, maxa);
	swap(stb, maxb);
	return (1);
}
