/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:12:41 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/13 15:15:10 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		if (!*stack_a)
		{
			*stack_a = *stack_b;
			*stack_b = (*stack_b)->next;
			(*stack_a)->next = NULL;
		}
		else
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			temp->next = *stack_a;
			*stack_a = temp;
		}
	}
	return (*stack_a);
}

void	check_digits(char *str, t_list **start)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 48 && str[i] <= 57) || \
			 str[i] == '\t' || str[i] == '-' || str[i] == '+'))
			err_not_numeric(start);
		i++;
	}
}
