/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:14:11 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 01:40:42 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		*one_more(int *stack, int *max)
{
	int		*newst;
	int		i;

	(*max)++;
	if (!(newst = malloc(sizeof(int) * (*max))))
		return (NULL);
	newst[0] = 0;
	i = -1;
	while (++i < (*max) - 1)
		newst[i + 1] = stack[i];
	free(stack);
	return (newst);
}

int		*one_less(int *stack, int *max)
{
	int		*newst;
	int		i;

	(*max)--;
	if (!(newst = malloc(sizeof(int) * (*max))))
		return (NULL);
	i = -1;
	while (++i < *max)
		newst[i] = stack[i + 1];
	free(stack);
	return (newst);
}

int		push(int **st1, int *m1, int **st2, int *m2)
{
	if (*m2 == 0)
		return (1);
	if (!(*st1 = one_more(*st1, m1)))
		return (0);
	(*st1)[0] = (*st2)[0];
	if ((*m2) - 1 == 0)
	{
		(*m2)--;
		free(*st2);
		*st2 = NULL;
		return (1);
	}
	if (!(*st2 = one_less(*st2, m2)))
		return (0);
	return (1);
}
