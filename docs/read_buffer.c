static int	read_buffer(int fd, char **backup)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	buffer[bytes_read] = '\0';
	*backup = ft_strjoin_free(*backup, buffer);
	if (!*backup)
		return (-1);
	return (bytes_read);
}
