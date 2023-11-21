/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:36:16 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/21 10:44:15 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

// # ifndef BUFFFER_SIZE
// #  define BUFFER_SIZE 5
// # endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
#endif