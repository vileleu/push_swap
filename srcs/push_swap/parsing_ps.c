/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:23:19 by vico              #+#    #+#             */
/*   Updated: 2021/03/20 16:32:37 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		parsing_ps(t_ps *ps, char **av)
{
	if (!(check_av(av)))
		return (print_err(ERR));
	if (max_min(av, "+2147483647", "-2147483648") < 0)
		return (print_err(ERR));
	if (!(ps->sta = create_stack(av, ps->ma)))
		return (print_err(ERR_M));
	if (!(no_duplicates(ps->sta, ps->ma)))
	{
		free(ps->sta);
		return (print_err(ERR));
	}
	return (1);
}
