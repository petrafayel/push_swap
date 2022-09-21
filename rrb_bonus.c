/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:44 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/18 18:37:16 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	}
	return (*start);
}
