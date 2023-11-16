/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:42 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/16 19:01:04 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_newline(char *s) {
	int i;
	i = 0;
	while (s[i]) {
		if (s[i] == '\n') return 1;
	i++;
	}
	return 0;
}

//reads my txt file
char *readtxt(int fd, char *buffer)
{
    ssize_t bytes_read;
    char *tempbuffer;

    tempbuffer = malloc((BUFFER_SIZE + 1));

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, tempbuffer, BUFFER_SIZE);
            tempbuffer[bytes_read] = '\0';
            buffer = ft_strjoin(buffer, tempbuffer);
    }
    free(tempbuffer);
    return buffer;
}

char *read_first_line(char *tempbuffer)
{
	int i;
	char *line;
	
	i = 0;
	if (!tempbuffer) return NULL;
	while (tempbuffer[i] && tempbuffer[i] != '\n')
		i++;
	line = malloc(i + 1);
	i = 0;
	while (tempbuffer[i] != '\n' && tempbuffer[i])
	{
		line[i] = tempbuffer[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

// gets the remainder
// char	*get_rem(char *buffer)
// {
// 		int i = 0;
// 		int j = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (buffer[i] == '\n') 
// 		i++;
// 	char *tempbuffer = malloc(ft_strlen(buffer) - i + 1);
// 		if(!tempbuffer) return NULL;
// 	while (buffer[i]) 
// 	{
// 		tempbuffer[j] = buffer[i];
// 		i++;
// 		j++;
// 	}
// 	tempbuffer[j] = '\0';
// 	free(buffer);
// 	return(tempbuffer);
// }

// main of all my extra functions
char	*get_next_line(int fd)
{
	static char *buffer;
	char *tempbuffer;
	
	buffer = readtxt(fd, buffer);
	tempbuffer = read_first_line(buffer);
	buffer = get_rem(buffer);
	return (tempbuffer);
}

// int	main()
// {
// 	int i = 0;
// 	int fd = open("mytextfile.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	if (str == NULL)
// 		printf("file could not read\n");

// 	else
// 		while (i < 4)
// 		{
// 			str = get_next_line(fd);
// 			printf("%d =%s\n", i, str);
// 			i++;
// 		}
// 	free(str);
// 	close(fd);
// 	return (0);
// }

int main(int argc, char **argv)
{
    int fd;
    char *line;
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening the file");
        return (1);
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);   // Free the line after using it
    }
    close(fd);
    return (0);
}

















// 1. reader functie

// 2. line printer

// 3. line part remover om remaining over te houden

// 4. return (line)