/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:12:30 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/11 18:18:14 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		ac;
	int		ati;
	t_list	*top;

	if (argc == 1)
		return (0);
	top = NULL;
	ac = argc - 1;
	ati = ft_atoi(argv[ac], &top);
	top = init_stack(ati);
	top->index = ac - 1;
	ac--;
	while (ac > 0)
	{
		ati = ft_atoi(argv[ac], &top);
		top = add_beg(&top, ati);
		top->index = ac - 1;
		ac--;
	}
	if (duplicates(&top) == 0)
		err(&top);
	push_swap(&top);
	free_list(&top);
	return (0);
}
