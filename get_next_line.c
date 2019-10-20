/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:30:53 by sirvin            #+#    #+#             */
/*   Updated: 2019/10/13 18:30:54 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

char	*check_remain(char *remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			free(remainder);
			remainder = ft_strdup(++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strclr(remainder);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int		get_line(const int fd, char **line, char **remainder)
{
	int				byte_read;
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;

	p_n = check_remain(*remainder, line);
	while (!p_n && (byte_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			*remainder = ft_strdup(++p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || remainder <0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (byte_read  || ft_strlen(*remainder) || ft_strlen(*line)) ? 1 : 0;
}

GNL		*new_el(int fd)
{
	GNL *new;

	if(!(new = (GNL *)malloc(sizeof(GNL))))
		return (NULL);
	new->fd = fd;
	new->remainder = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static GNL	*head;
	GNL			*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (head == NULL)
		head = new_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_el(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->remainder));
}

int		main(void)
{
	char	*line;
	int		fd;
 
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
