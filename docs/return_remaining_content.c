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
