/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:27:29 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:27:31 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	*stack_a = rra(stack_a);
	*stack_b = rrb(stack_b);
}
