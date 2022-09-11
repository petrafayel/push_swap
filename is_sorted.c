/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:12:21 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:37:44 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **start)
{
	t_list	*temp;

	temp = *start;
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	err(t_list **start)
{
	free_list(start);
	write(2, "Error\n", 6);
	exit (1);
}

void	err_not_numeric(t_list **start)
{
	if (*start)
		free_list(start);
	write(2, "Error\n", 6);
	exit (1);
}

void	err_min_max(long long data, t_list **start)
{
	if (min_max(data) == 0)
	{
		if (*start)
			free_list(start);
		write(2, "Error\n", 6);
		exit (1);
	}
}
