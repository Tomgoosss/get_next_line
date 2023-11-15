/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:42 by tgoossen          #+#    #+#             */
/*   Updated: 2023/11/15 13:59:43 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//reads my txt file
char *gettxt(int fd)
{
	
}
// reads first line
char *read_first_line()
{
	
}

// gets the remainder
char	*get_a_line()
{
	
}

// main of all my extra functions
char	*get_next_line(int fd)
{
	static char buffer;
	char tempbuffer;
	
	tempbuffer = gettxt(fd);
}

int	main()
{
	int i = 0;
	int fd = open("mytextfile.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	if (str == NULL)
		printf("file could not read\n");

	else
		while (i < 2)
		{
			printf("%d =%s\n", i, str);
			i++;
		}
	free(str);
	close(fd);
	return (0);
}


















// 1. reader functie

// 2. line printer

// 3. line part remover om remaining over te houden

// 4. return (line)