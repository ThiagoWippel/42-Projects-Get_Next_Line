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
