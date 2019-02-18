/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 21:45:16 by bgonzale          #+#    #+#             */
/*   Updated: 2018/11/04 11:43:16 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_nl(char **stack, char **line, int fd, int num_bytes)
{
	char	*temp;
	int		pos;
	int		len;

	pos = 0;
	while (stack[fd][pos] != '\n' && stack[fd][pos] != '\0')
		pos++;
	if (stack[fd][pos] == '\n')
	{
		len = pos;
		*line = ft_strsub(stack[fd], 0, len);
		temp = ft_strdup(stack[fd] + pos + 1);
		free(stack[fd]);
		stack[fd] = temp;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else if (stack[fd][pos] == '\0')
	{
		if (num_bytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *stack[42];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			num_bytes;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((num_bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[num_bytes] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strnew(1);
		temp = ft_strjoin(stack[fd], buf);
		free(stack[fd]);
		stack[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (num_bytes < 0)
		return (-1);
	else if (num_bytes == 0 && (stack[fd] == NULL || stack[fd][0] == '\0'))
		return (0);
	return (ft_nl(stack, line, fd, num_bytes));
}
