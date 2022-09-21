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

void	check_digits(char *str, t_list **start)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 48 && str[i] <= 57) || \
			 str[i] == '\t' || str[i] == '-' || str[i] == '+'))
			err_not_numeric(start);
		i++;
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
	push_swap(&top);
	free_list(&top);
	return (0);
}
