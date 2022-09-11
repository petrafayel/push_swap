/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:09:23 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/27 13:09:45 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_list **start)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *start;
	second = first->next;
	third = second->next;
	if (first->data > second->data && third->data > first->data)
		first = sa(&first);
	else if (first->data > second->data && second->data > third->data)
	{
		first = sa(&first);
		first = rra(&first);
	}
	else if (first->data > second->data && second->data < third->data)
		first = ra(&first);
	else if (third->data < second->data && third->data > first->data)
	{
		first = sa(&first);
		first = ra(&first);
	}
	else if (first->data < second->data && first->data > third->data)
		first = rra(&first);
	*start = first;
}
