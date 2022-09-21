/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:09:29 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:23:27 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_list **start)
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
		else if ((*start)->index <= counter + 15)
		{
			stack_b = pb(start, &stack_b);
			counter++;
		}
		else
			*start = ra(start);
	}
	back_to_a(start, &stack_b);
}
