/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:39 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/21 15:21:31 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*zin;
	unsigned char	let;
	size_t			i;

	zin = (unsigned char *)s;
	let = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		zin[i] = let;
		i++;
	}
	return (zin);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tsize;
	void	*mem;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tsize = nmemb * size;
	mem = malloc(tsize);
	if (mem)
		ft_memset(mem, 0, tsize);
	return (mem);
}

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

char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (!s)
		s = "";
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		y;
	int		s1s2count;
	char	*copy;

	s1s2count = ft_strlen(s1) + ft_strlen(s2);
	copy = (char *)malloc((s1s2count + 1) * sizeof(char));
	i = 0;
	if (copy == 0)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		copy[i] = s2[y];
		y++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
