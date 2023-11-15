/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:16 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/15 13:23:34 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include <stdlib.h>
# define BUFFER_SIZE 10000

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		ft_strchr(char *s, int c);
char	*ft_strlcpy(char *dest, char *src, size_t size);
#endif