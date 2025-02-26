/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:15:37 by sirvin            #+#    #+#             */
/*   Updated: 2019/09/17 13:15:47 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len_c_stop(const char *str, int start, char c_stop)
{
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && (str[start] != c_stop))
	{
		start++;
		counter++;
	}
	return (counter);
}

static int			ft_split_count(char const *s, char c)
{
	int		is_word;
	int		count_word;
	int		counter;
	char	*str;

	str = (char *)s;
	counter = 0;
	count_word = 0;
	while (str[counter])
	{
		is_word = 0;
		while ((str[counter] != (char)c) && str[counter + 1])
		{
			if (is_word == 0)
			{
				is_word = 1;
				count_word++;
			}
			counter++;
		}
		counter++;
	}
	return (count_word);
}

char				**ft_strsplit(char const *s, char c)
{
	int				count_word;
	int				i;
	unsigned int	counter;
	char			**array_s;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	counter = 0;
	count_word = ft_split_count(str, c);
	if (!(array_s = (char**)ft_memalloc(sizeof(char**) * (count_word + 1))))
		return (NULL);
	i = -1;
	while (++i < count_word)
	{
		while ((str[counter] == (char)c) && str[counter])
			counter++;
		array_s[i] = ft_strsub(str, counter, ft_len_c_stop(str, counter, c));
		while ((str[counter] != (char)c) && str[counter])
			counter++;
	}
	array_s[i] = 0;
	return (array_s);
}
