/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:39 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/15 13:23:06 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}

int	ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == '\0')
	{
		return (i);
	}
	return (0);
}

char	*ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	if (src)
		free(src);
	return (dest);
}
