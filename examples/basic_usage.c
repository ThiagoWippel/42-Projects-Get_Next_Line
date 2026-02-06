/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twippel- <twippel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:00:00 by twippel-          #+#    #+#             */
/*   Updated: 2025/02/06 00:00:00 by twippel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error: Could not create test file\n");
		return (1);
	}
	
	write(fd, "Line 1: Hello, World!\n", 22);
	write(fd, "Line 2: This is get_next_line\n", 31);
	write(fd, "Line 3: Testing multiple lines\n", 32);
	write(fd, "Line 4: No newline at end", 25);
	close(fd);

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open file for reading\n");
		return (1);
	}

	printf("\n=== Reading file with get_next_line ===\n\n");
	
	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		if (line[ft_strlen(line) - 1] != '\n')
			printf(" (no newline)");
		printf("\n");
		free(line);
	}

	printf("\n=== Read %d lines successfully ===\n", line_count);
	
	close(fd);
  
	unlink("test.txt");
	
	return (0);
}
