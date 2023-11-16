/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:39 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/16 18:26:54 by tgoossen         ###   ########.fr       */
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

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		y;
// 	int		s1s2count;
// 	char	*copy;

// 	s1s2count = ft_strlen(s1) + ft_strlen(s2);
// 	copy = (char *)malloc((s1s2count + 1) * sizeof(char));
// 	i = 0;
// 	if (copy == 0)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		copy[i] = s1[i];
// 		i++;
// 	}
// 	y = 0;
// 	while (s2[y])
// 	{
// 		copy[i] = s2[y];
// 		y++;
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

char    *ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *str;
	
	    if (!s1)
        s1 = "";

    if (!s2)
        s2 = "";
	
    if (!s2)
        return (NULL);
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s1 && s1[i])
        str[j++] = s1[i++];
    i = 0;
    while (s2[i])
        str[j++] = s2[i++];
    str[j] = '\0';
    return (str);
}
