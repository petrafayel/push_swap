/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:13:05 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/18 18:39:12 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

int		ft_atoi(char **str, t_list **start);
t_list	*add_end(t_list **head, int data);
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
int		duplicates(t_list **start);
void	free_list(t_list **start);
void	err(t_list **start);
void	err_not_numeric(t_list **start);
void	err_min_max(long long data, t_list **start);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, int start, size_t len);
int		ft_newline(char *s);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);
int		ft_strcmp(char *s1, char *s2);
void	checker_tools(char *str, t_list **stack_a, t_list **stack_b);
void	err_checker(t_list **stack_a, t_list **stack_b);
int		min_max(long long data);
int		duplicates(t_list **start);
int		list_len(t_list **start);
void	check_spaces(char *str, t_list **start);
void	check_digits(char *str, t_list **start);

#endif
