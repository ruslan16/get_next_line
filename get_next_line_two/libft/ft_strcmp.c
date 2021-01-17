/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:05:37 by sirvin            #+#    #+#             */
/*   Updated: 2019/09/16 14:05:44 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ns1;
	unsigned char *ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	while (*ns1 && (*ns1 == *ns2))
	{
		ns1++;
		ns2++;
	}
	return (*ns1 - *ns2);
}
