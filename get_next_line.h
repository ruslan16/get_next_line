/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:31:03 by sirvin            #+#    #+#             */
/*   Updated: 2019/10/13 18:31:31 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

typedef struct get_next_line
{
	int		fd;
	char	*remainder;
	struct 	get_next_line *next;
}			GNL;

# include "stdlib.h"
# include "libft/libft.h"
# include "unistd.h"

int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_ine(const int fd, char **line);
int		get_next_line(int fd, char **line);
GNL		*new_el(int fd);

#endif
