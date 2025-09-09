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
