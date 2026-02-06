/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
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
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

int	g_test_count = 0;
int	g_pass_count = 0;

void	print_test_header(const char *test_name)
{
	printf("\n" YELLOW "========================================\n");
	printf("TEST: %s\n", test_name);
	printf("========================================\n" RESET);
}

void	assert_string_equals(const char *expected, const char *actual, const char *test_name)
{
	g_test_count++;
	if (expected == NULL && actual == NULL)
	{
		printf(GREEN "✓ PASS" RESET " [%d]: %s (both NULL)\n", g_test_count, test_name);
		g_pass_count++;
		return;
	}
	if (expected == NULL || actual == NULL)
	{
		printf(RED "✗ FAIL" RESET " [%d]: %s\n", g_test_count, test_name);
		printf("  Expected: %s\n", expected ? expected : "NULL");
		printf("  Got:      %s\n", actual ? actual : "NULL");
		return;
	}
	if (strcmp(expected, actual) == 0)
	{
		printf(GREEN "✓ PASS" RESET " [%d]: %s\n", g_test_count, test_name);
		g_pass_count++;
	}
	else
	{
		printf(RED "✗ FAIL" RESET " [%d]: %s\n", g_test_count, test_name);
		printf("  Expected: \"%s\"\n", expected);
		printf("  Got:      \"%s\"\n", actual);
	}
}

void	test_basic_lines(void)
{
	int		fd;
	char	*line;

	print_test_header("Basic Lines with Newlines");
	
	fd = open("test_basic.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "Line 1\n", 7);
	write(fd, "Line 2\n", 7);
	write(fd, "Line 3\n", 7);
	close(fd);

	fd = open("test_basic.txt", O_RDONLY);
	
	line = get_next_line(fd);
	assert_string_equals("Line 1\n", line, "First line");
	free(line);

	line = get_next_line(fd);
	assert_string_equals("Line 2\n", line, "Second line");
	free(line);

	line = get_next_line(fd);
	assert_string_equals("Line 3\n", line, "Third line");
	free(line);

	line = get_next_line(fd);
	assert_string_equals(NULL, line, "EOF returns NULL");

	close(fd);
	unlink("test_basic.txt");
}

void	test_no_newline_at_end(void)
{
	int		fd;
	char	*line;

	print_test_header("File Without Trailing Newline");
	
	fd = open("test_no_nl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "Line 1\n", 7);
	write(fd, "Line 2 without newline", 22);
	close(fd);

	fd = open("test_no_nl.txt", O_RDONLY);
	
	line = get_next_line(fd);
	assert_string_equals("Line 1\n", line, "First line with newline");
	free(line);

	line = get_next_line(fd);
	assert_string_equals("Line 2 without newline", line, "Last line without newline");
	free(line);

	line = get_next_line(fd);
	assert_string_equals(NULL, line, "EOF after line without newline");

	close(fd);
	unlink("test_no_nl.txt");
}

void	test_empty_file(void)
{
	int		fd;
	char	*line;

	print_test_header("Empty File");
	
	fd = open("test_empty.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(fd);

	fd = open("test_empty.txt", O_RDONLY);
	
	line = get_next_line(fd);
	assert_string_equals(NULL, line, "Empty file returns NULL");

	close(fd);
	unlink("test_empty.txt");
}

void	test_empty_lines(void)
{
	int		fd;
	char	*line;

	print_test_header("Empty Lines");
	
	fd = open("test_empty_lines.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "\n", 1);
	write(fd, "\n", 1);
	write(fd, "Content\n", 8);
	write(fd, "\n", 1);
	close(fd);

	fd = open("test_empty_lines.txt", O_RDONLY);
	
	line = get_next_line(fd);
	assert_string_equals("\n", line, "First empty line");
	free(line);

	line = get_next_line(fd);
	assert_string_equals("\n", line, "Second empty line");
	free(line);

	line = get_next_line(fd);
	assert_string_equals("Content\n", line, "Line with content");
	free(line);

	line = get_next_line(fd);
	assert_string_equals("\n", line, "Last empty line");
	free(line);

	close(fd);
	unlink("test_empty_lines.txt");
}

void	test_long_line(void)
{
	int		fd;
	char	*line;
	char	long_line[10001];

	print_test_header("Very Long Line");
	
	memset(long_line, 'A', 10000);
	long_line[10000] = '\0';

	fd = open("test_long.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, long_line, 10000);
	write(fd, "\n", 1);
	close(fd);

	fd = open("test_long.txt", O_RDONLY);
	
	line = get_next_line(fd);
	strcat(long_line, "\n");
	assert_string_equals(long_line, line, "10000 character line");
	free(line);

	close(fd);
	unlink("test_long.txt");
}

void	test_invalid_fd(void)
{
	char	*line;

	print_test_header("Invalid File Descriptor");
	
	line = get_next_line(-1);
	assert_string_equals(NULL, line, "Negative FD returns NULL");

	line = get_next_line(999);
	assert_string_equals(NULL, line, "Invalid FD returns NULL");
}

void	print_summary(void)
{
	printf("\n");
	printf("========================================\n");
	printf("TEST SUMMARY\n");
	printf("========================================\n");
	printf("Total tests:  %d\n", g_test_count);
	printf(GREEN "Passed:       %d\n" RESET, g_pass_count);
	if (g_test_count - g_pass_count > 0)
		printf(RED "Failed:       %d\n" RESET, g_test_count - g_pass_count);
	printf("========================================\n");
	
	if (g_pass_count == g_test_count)
		printf(GREEN "✓ ALL TESTS PASSED!\n" RESET);
	else
		printf(RED "✗ SOME TESTS FAILED\n" RESET);
}

int	main(void)
{
	printf("\n");
	printf("╔════════════════════════════════════════╗\n");
	printf("║   Get Next Line - Test Suite          ║\n");
	printf("║   BUFFER_SIZE: %-5d                  ║\n", BUFFER_SIZE);
	printf("╚════════════════════════════════════════╝\n");

	test_basic_lines();
	test_no_newline_at_end();
	test_empty_file();
	test_empty_lines();
	test_long_line();
	test_invalid_fd();

	print_summary();

	return (g_test_count == g_pass_count ? 0 : 1);
}
