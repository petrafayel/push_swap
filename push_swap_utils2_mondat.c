/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:19:20 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:30:18 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **start)
{
	t_list	*prev;

	while (*start)
	{
		prev = *start;
		*start = (*start)->next;
		free (prev);
	}
}

int	duplicates(t_list **start)
{
	t_list	*first;
	t_list	*second;

	first = *start;
	while (first->next)
	{
		second = first->next;
		while (second)
		{
			if (first->data == second->data)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}

void	indices(t_list **start)
{
	int		index;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *start;
	while (temp1)
	{
		index = 0;
		temp2 = *start;
		while (temp2)
		{
			if (temp2->data < temp1->data)
				index++;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
}

t_list	*add_end(t_list **head, int data)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*head)
	{
		temp1 = init_stack(data);
		return (temp1);
	}
	temp1 = init_stack(data);
	temp2 = *head;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->data = data;
	temp1->next = NULL;
	return (*head);
}
