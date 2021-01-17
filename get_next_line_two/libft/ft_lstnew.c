/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:33:43 by sirvin            #+#    #+#             */
/*   Updated: 2019/09/16 16:34:05 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_cell;

	if (!(new_cell = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(new_cell->content = (void*)ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new_cell->content, content, content_size);
		new_cell->content_size = content_size;
	}
	else
	{
		new_cell->content = NULL;
		new_cell->content_size = 0;
	}
	new_cell->next = NULL;
	return (new_cell);
}
