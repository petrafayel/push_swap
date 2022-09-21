/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:44 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/27 13:14:45 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rrb(t_list **start)
{
	t_list	*prev;
	t_list	*last;

	prev = *start;
	if (prev && prev->next)
	{
		while (prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = *start;
		*start = last;
		write(1, "rrb\n", 4);
	}
	return (*start);
}
