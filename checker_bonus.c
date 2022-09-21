/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:24:40 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/18 14:56:00 by rapetros         ###   ########.fr       */
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
			break ;
		checker_tools(str, stack_a, &stack_b);
	}
	if (list_len(&stack_b) > 0 || !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (is_sorted(stack_a))
		write(1, "OK\n", 3);
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

void	check_spaces(char *str, t_list **start)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
	{
		if (*start)
			err(start);
		else
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
}

int	main(int argc, char **argv)
{
	int		ac;
	t_list	*top;

	if (argc == 1)
		return (0);
	top = NULL;
	ac = 1;
	while (ac < argc)
	{
		check_spaces(argv[ac], &top);
		check_digits(argv[ac], &top);
		while (*argv[ac])
		{
			top = add_end(&top, ft_atoi(&argv[ac], &top));
			while ((*argv[ac] == ' ' || *argv[ac] == '\t') && *argv[ac])
				argv[ac]++;
		}
		ac++;
	}
	if (duplicates(&top) == 0)
		err(&top);
	checker(&top);
	free_list(&top);
	return (0);
}
