/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:13:35 by rapetros          #+#    #+#             */
/*   Updated: 2022/08/13 15:20:19 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sa(t_list **start)
{
	t_list	*temp;

	temp = *start;
	if (temp && temp->next)
	{
		temp = temp->next;
		(*start)->next = temp->next;
		temp->next = *start;
		*start = temp;
		write(1, "sa\n", 3);
	}
	return (*start);
}
