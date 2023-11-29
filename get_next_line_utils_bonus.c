/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:39 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/29 11:48:37 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_nlcheck(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		o;

	o = 0;
	if (s1 == NULL)
		i = ft_strlen(s2);
	else
		i = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(i + 1);
	if (!new)
		return (ft_free2(&s1));
	i = 0;
	while (s1 != NULL && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[o])
		new[i++] = s2[o++];
	new[i] = '\0';
	ft_free2(&s1);
	return (new);
}