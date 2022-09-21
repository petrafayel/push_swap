/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:12:57 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/11 18:18:07 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **start)
{
	if (list_len(start) == 1)
		return ;
	if (list_len(start) == 2)
	{
		if (!is_sorted(start))
			*start = sa(start);
	}
	else if (list_len(start) == 3)
		case_1(start);
	else if (list_len(start) <= 10)
		case_2(start);
	else if (list_len(start) <= 100)
		case_3(start);
	else if (list_len(start) <= 500)
		case_4(start);
}
