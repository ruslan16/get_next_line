/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:41:57 by sirvin            #+#    #+#             */
/*   Updated: 2019/10/22 17:22:30 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **rem, char **line, int fd, int byte_read)
{
	char	*temp;
	int		size;

	size = 0;
	while (rem[fd][size] != '\n' && rem[fd][size] != '\0')
		size++;
	if (rem[fd][size] == '\n')
	{
		*line = ft_strsub(rem[fd], 0, size);
		temp = ft_strdup(rem[fd] + size + 1);
		free(rem[fd]);
		rem[fd] = temp;
		if (rem[fd][0] == '\0')
			ft_strdel(&rem[fd]);
	}
	else if (rem[fd][size] == '\0')
	{
		if (byte_read == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(rem[fd]);
		ft_strdel(&rem[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*rem[255];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			byte_read;

	if ((fd < 0 && line == NULL) || (BUFF_SIZE < 0))
		return (-1);
	while ((byte_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte_read] = '\0';
		if (!rem[fd])
			rem[fd] = ft_strnew(0);
		tmp = ft_strjoin(rem[fd], buff);
		free(rem[fd]);
		rem[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (byte_read < 0)
		return (-1);
	else if (byte_read == 0 && (rem[fd] == NULL || rem[fd][0] == '\0'))
		return (0);
	return (get_line(rem, line, fd, byte_read));
}
