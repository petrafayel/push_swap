/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:24:40 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/11 17:20:04 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_list **stack_a)
{
	char		*str;
	t_list		*stack_b;

	stack_b = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		if (ft_strcmp(str, "Error\n") == 0)
		{
			free_list(stack_a);
			write(2, "Error\n", 6);
			exit (1);
		}
		checker_tools(str, stack_a, &stack_b);
	}
}

void	checker_tools(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		*stack_a = sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		*stack_b = sb(stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		*stack_a = pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		*stack_b = pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		*stack_a = ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		*stack_b = rb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		*stack_a = rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		*stack_b = rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else
		err_checker(stack_a, stack_b);
}

void	err_checker(t_list **stack_a, t_list **stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

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
	ac--;
	while (ac > 0)
	{
		ati = ft_atoi(argv[ac], &top);
		top = add_beg(&top, ati);
		ac--;
	}
	checker(&top);
	if (is_sorted(&top))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&top);
	return (0);
}
