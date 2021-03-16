/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vico <vico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:38:45 by vico              #+#    #+#             */
/*   Updated: 2021/03/16 01:41:54 by vico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		print_err(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (0);
}

int		free_err(char *s)
{
	free(s);
	return (0);
}

int		print_free_err(char *msg, char *s)
{
	ft_putstr_fd(msg, 2);
	free(s);
	return (0);
}

int		free_check(t_o *check)
{
	t_list	*tmp;

	if (check->ma)
		free(check->sta);
	if (check->mb)
		free(check->stb);
	while (check->line)
	{
		tmp = check->line;
		check->line = check->line->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}
