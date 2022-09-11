/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:09:16 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:34:20 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_list **start)
{
	t_list	*stack_b;
	int		min_p;

	stack_b = NULL;
	if (is_sorted(start))
		return ;
	while (list_len(start) != 3)
	{
		min_p = min_pos(*start);
		if (min_p <= list_len(start) / 2)
		{
			while ((*start)->data != list_min(*start))
				*start = ra(start);
		}
		else
		{
			while ((*start)->data != list_min(*start))
				*start = rra(start);
		}
		stack_b = pb(start, &stack_b);
	}
	case_1(start);
	while (stack_b)
		*start = pa(start, &stack_b);
}

int	min_pos(t_list *start)
{
	int	min;
	int	pos;

	pos = 0;
	min = list_min(start);
	while (start->data != min)
	{
		start = start->next;
		pos++;
	}
	return (pos);
}

int	list_min(t_list *start)
{
	int	min;

	min = start->data;
	start = start->next;
	while (start)
	{
		if (start->data < min)
			min = start->data;
		start = start->next;
	}
	return (min);
}
