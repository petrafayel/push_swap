/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:12:49 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/13 15:15:26 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	return (*stack_b);
}
