/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:14:14 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 18:22:57 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		parsing_c(t_c *c, char **av)
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
