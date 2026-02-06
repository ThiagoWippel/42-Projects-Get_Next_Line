/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_example.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twippel- <twippel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:00:00 by twippel-          #+#    #+#             */
/*   Updated: 2025/02/06 00:00:00 by twippel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		line_count;

	printf("=== Get Next Line - STDIN Example ===\n");
	printf("Type text and press Enter. Press Ctrl+D to exit.\n\n");
	
	line_count = 0;
	while ((line = get_next_line(0)) != NULL)
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
	}

	printf("\n=== Read %d lines from stdin ===\n", line_count);
	
	return (0);
}
