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
	free(*backup);
	*backup = temp;
	return (line);
}
