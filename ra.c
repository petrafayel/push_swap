/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:13:24 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/13 15:13:25 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ra(t_list **start)
{
	t_list	*temp;

	temp = *start;
	while (temp->next)
		temp = temp->next;
	temp->next = *start;
	temp = *start;
	*start = (*start)->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
	return (*start);
}
