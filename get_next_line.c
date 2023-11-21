/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:42 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/21 15:42:01 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	// free(buf);
	return (temp);
}

char *readtxt(int fd, char *buffer)
{
    ssize_t bytes_read;
    char *tempbuffer;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));

    tempbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
    {
		bytes_read = read(fd, tempbuffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(tempbuffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
        tempbuffer[bytes_read] = '\0';
        buffer = ft_free(buffer, tempbuffer);
    }
    free(tempbuffer);
    return buffer;
}

char *read_first_line(char *tempbuffer)
{
	int	i;
	int	o;
	char *line;

	i = 0;
	o = 0;
	while (tempbuffer[i] && tempbuffer[i] != '\n')
		i++;
	if (tempbuffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(tempbuffer);
		return (NULL);
	}
	while (o < i)
	{
		line[o] = tempbuffer[o];
		o++;
	}
	line[i] = '\0';
	return(line);
}

char	*get_rem(char *buffer)
{
		int i;
		int j;
		char *tempbuffer;

		i = 0;
		j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' ) 
		i++;
	tempbuffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if(!tempbuffer)
	{
		free(buffer);
		return NULL;
	}
	while (buffer[i]) 
	{
		tempbuffer[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	tempbuffer[j] = '\0';
	return(tempbuffer);
}

// main of all my extra functions
char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char *tempbuffer;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	buffer = readtxt(fd, buffer);
	if (buffer == NULL || buffer[0] == '\0')
		return(NULL);
	tempbuffer = read_first_line(buffer);
	buffer = get_rem(buffer);

	return (tempbuffer);
}

// int main()
// {
//     int i = 0;
//     int fd = open("mytextfile.txt", O_RDONLY);
//     char *str;

//     while (i < 10)
//     {
//         str = get_next_line(fd);
//         if (str == NULL)
//         {
//             // Handle read error
//             break;
//         }
//         printf("%d = %s\n", i, str);
//         free(str);
//         i++;
//     }
//     close(fd);
//     return 0;
// }
