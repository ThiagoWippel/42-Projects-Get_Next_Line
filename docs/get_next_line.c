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
