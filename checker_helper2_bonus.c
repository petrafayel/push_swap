/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:17:36 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/11 18:22:48 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	err(t_list **start)
{
	free_list(start);
	write(2, "Error\n", 6);
	exit (1);
}

void	err_not_numeric(t_list **start)
{
	if (*start)
		free_list(start);
	write(2, "Error\n", 6);
	exit (1);
}

void	err_min_max(long long data, t_list **start)
{
	if (min_max(data) == 0)
	{
		if (*start)
			free_list(start);
		write(2, "Error\n", 6);
		exit (1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
			i++;
	return (s1[i] - s2[i]);
}

int	min_max(long long data)
{
	if (data > 2147483647 || data < -2147483648)
		return (0);
	return (1);
}
