/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:09:47 by rapetros          #+#    #+#             */
/*   Updated: 2022/09/18 14:56:43 by rapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_line(char	*s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*s)
		return (NULL);
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			tmp = ft_substr(s, 0, i + 1);
			return (tmp);
		}
		i++;
	}
	tmp = ft_strdup(s);
	return (tmp);
}

char	*ft_readline(int fd, char *s)
{
	char	buffer[BUFFER_SIZE + 1];
	int		size;

	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || BUFFER_SIZE <= 0)
			return (NULL);
		buffer[size] = '\0';
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (size == 0 || ft_newline(buffer) > -1)
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*temp;
	char		*newline;

	line = ft_readline(fd, line);
	if (!line)
		return (NULL);
	newline = ft_line(line);
	if (ft_newline(line) > -1)
	{
		temp = line;
		line = ft_substr(line, ft_newline(line) + 1, \
				ft_strlen(line) - (ft_strlen(newline)));
		free (temp);
	}
	else
	{
		free (line);
		line = NULL;
	}	
	return (newline);
}

int	duplicates(t_list **start)
{
	t_list	*first;
	t_list	*second;

	first = *start;
	while (first->next)
	{
		second = first->next;
		while (second)
		{
			if (first->data == second->data)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}

int	list_len(t_list **start)
{
	t_list	*temp;
	int		count;

	if (!*start)
		return (0);
	temp = *start;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
