/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:13:14 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:29:41 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	list_len(t_list **start)
{
	t_list	*temp;
	int		count;

	if (!*start)
		return (0);
	temp = *start;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	min_max(long long data)
{
	if (data > 2147483647 || data < -2147483648)
		return (0);
	return (1);
}
