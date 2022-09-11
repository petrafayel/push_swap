/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:09:35 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:24:24 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_4(t_list **start)
{
	t_list	*stack_b;
	int		counter;

	if (is_sorted(start))
		return ;
	counter = 0;
	stack_b = NULL;
	indices(start);
	while (*start)
	{
		if ((*start)->index <= counter)
		{
			stack_b = pb(start, &stack_b);
			stack_b = rb(&stack_b);
			counter++;
		}
		else if ((*start)->index <= counter + 30)
		{
			stack_b = pb(start, &stack_b);
			counter++;
		}
		else
			*start = ra(start);
	}
	back_to_a(start, &stack_b);
}

void	back_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if (max_index_pos(*stack_b) <= list_len(stack_b) / 2)
		{
			while ((*stack_b)->index != max_index(*stack_b))
				*stack_b = rb(stack_b);
			*stack_a = pa(stack_a, stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_index(*stack_b))
				*stack_b = rrb(stack_b);
			*stack_a = pa(stack_a, stack_b);
		}
	}
}

int	max_index(t_list *start)
{
	int		max;
	t_list	*temp;

	temp = start;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	max_index_pos(t_list *start)
{
	int		max;
	int		pos;
	t_list	*temp;

	pos = 0;
	temp = start;
	max = max_index(temp);
	while (temp->index != max)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}
