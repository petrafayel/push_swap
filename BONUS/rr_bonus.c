/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:27:23 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:27:25 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	*stack_a = ra(stack_a);
	*stack_b = rb(stack_b);
}