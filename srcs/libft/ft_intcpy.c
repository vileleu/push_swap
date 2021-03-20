/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:23:29 by vico              #+#    #+#             */
/*   Updated: 2021/03/20 17:22:40 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intcpy(int *tab, int m)
{
	int		*new;
	int		i;

	if (!tab)
		return (NULL);
	if (!(new = malloc(sizeof(int) * m)))
		return (NULL);
	i = -1;
	while (++i < m)
		new[i] = tab[i];
	return (new);
}
