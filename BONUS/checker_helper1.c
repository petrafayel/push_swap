/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:10:06 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/11 17:21:35 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*init_stack(int data)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list *));
	if (!temp)
		return (NULL);
	temp->data = data;
	temp->next = NULL;
	return (temp);
}

t_list	*add_beg(t_list **start, int data)
{
	t_list	*temp;

	temp = init_stack(data);
	temp->next = *start;
	*start = temp;
	return (*start);
}

int	ft_atoi(char *str, t_list **start)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str <= 32)
	{
		str++;
		if (!*str)
			exit (0);
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!*str)
		err(start);
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*(str++) - 48);
	if (*str && !(*str >= '0' && *str <= '9'))
		err_not_numeric(start);
	err_min_max((res * sign), start);
	return (res * sign);
}

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

int	is_sorted(t_list **start)
{
	t_list	*temp;

	temp = *start;
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}
