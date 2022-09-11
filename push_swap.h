/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:13:05 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/10 13:31:08 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

int		ft_atoi(char *str, t_list **start);
t_list	*add_beg(t_list **start, int data);
t_list	*init_stack(int data);
t_list	*sa(t_list **start);
t_list	*sb(t_list **start);
t_list	*pa(t_list **stack_a, t_list **stack_b);
t_list	*pb(t_list **stack_a, t_list **stack_b);
t_list	*ra(t_list **start);
t_list	*rb(t_list **start);
t_list	*rra(t_list **start);
t_list	*rrb(t_list **start);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **start);
int		list_len(t_list **start);
void	push_swap(t_list **start);
void	case_1(t_list **start);
void	case_2(t_list **start);
void	case_3(t_list **start);
void	case_4(t_list **start);
int		duplicates(t_list **start);
void	free_list(t_list **start);
int		min_pos(t_list *start);
int		list_min(t_list *start);
int		max_index_pos(t_list *start);
int		max_index(t_list *start);
t_list	*add_end(t_list **head, int data, int index);
void	back_to_a(t_list **stack_a, t_list **stack_b);
int		min_max(long long data);
void	indices(t_list **start);
void	err(t_list **start);
void	err_not_numeric(t_list **start);
void	err_min_max(long long data, t_list **start);

#endif
