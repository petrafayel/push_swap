/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:13:30 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/13 15:13:31 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rb(t_list **start)
{
	t_list	*temp;

	temp = *start;
	if (temp && temp->next)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = *start;
		temp = *start;
		*start = (*start)->next;
		temp->next = NULL;
		write(1, "rb\n", 3);
	}
	return (*start);
}
