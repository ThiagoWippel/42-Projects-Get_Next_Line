/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twippel- <twippel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:33:55 by twippel-          #+#    #+#             */
/*   Updated: 2025/09/08 14:00:00 by twippel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **backup)
{
	char	*newline_pos;
	char	*line;
	char	*temp;
	size_t	line_len;

	newline_pos = ft_strchr(*backup, '\n');
	if (!newline_pos)
		return (NULL);
	line_len = newline_pos - *backup + 1;
	line = ft_substr(*backup, 0, line_len);
	if (!line)
		return (NULL);
	temp = ft_substr(*backup, line_len, ft_strlen(*backup) - line_len);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(*backup);
	*backup = temp;
	return (line);
}

static int	read_buffer(int fd, char **backup)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (bytes_read);
	}
	buffer[bytes_read] = '\0';
	*backup = ft_strjoin_free(*backup, buffer);
	free(buffer);
	if (!*backup)
		return (-1);
	return (bytes_read);
}

static char	*return_remaining_content(char **backup)
{
	char	*line;

	if (!*backup || (*backup)[0] == '\0')
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (line);
}

static char	*initialize_backup(char **backup)
{
	char	*line;

	if (!*backup)
	{
		*backup = ft_strdup("");
		if (!*backup)
			return (NULL);
	}
	line = extract_line(backup);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	int			read_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = initialize_backup(&backup);
	if (line)
		return (line);
	while (1)
	{
		read_result = read_buffer(fd, &backup);
		if (read_result == -1)
		{
			free(backup);
			backup = NULL;
			return (NULL);
		}
		if (read_result == 0)
			return (return_remaining_content(&backup));
		line = extract_line(&backup);
		if (line)
			return (line);
	}
}
