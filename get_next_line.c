/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:42 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/13 15:33:09 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *tempbuffer[BUFFER_SIZE];
	ssize_t readbytes;
	
	readbytes = read(fd, tempbuffer, BUFFER_SIZE);
	if (readbytes < 0)
		return (-1);
	// printf("%s", tempbuffer);
	return tempbuffer;
}

int	main()
{
	int i = 0;
	int fd = open("mytextfile.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	if (str == -1)
		printf("file could not read\n");

	else
		while (i < 25)
		{
			printf("my file =%s", str);
			free(str);
			i++;
		}
	close(fd);
	return (0);
}