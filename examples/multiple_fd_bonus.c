/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_fd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twippel- <twippel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:00:00 by twippel-          #+#    #+#             */
/*   Updated: 2025/02/06 00:00:00 by twippel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1, fd2, fd3;
	char	*line;

	fd1 = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd1, "File 1 - Line 1\nFile 1 - Line 2\n", 33);
	close(fd1);

	fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd2, "File 2 - Line 1\nFile 2 - Line 2\n", 33);
	close(fd2);

	fd3 = open("file3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd3, "File 3 - Line 1\nFile 3 - Line 2\n", 33);
	close(fd3);

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	printf("=== Testing Multiple File Descriptors ===\n\n");

	line = get_next_line(fd1);
	printf("FD1: %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("FD2: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("FD3: %s", line);
	free(line);

	line = get_next_line(fd1);
	printf("FD1: %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("FD2: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("FD3: %s", line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);

	unlink("file1.txt");
	unlink("file2.txt");
	unlink("file3.txt");

	return (0);
}
