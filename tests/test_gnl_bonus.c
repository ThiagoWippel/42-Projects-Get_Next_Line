/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl_bonus.c                                   :+:      :+:    :+:   */
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

void	assert_string_equals(const char *expected, const char *actual,
		const char *test_name)
{
	g_test_count++;
	if (expected == NULL && actual == NULL)
	{
		printf(GREEN "✓ PASS" RESET " [%d]: %s\n", g_test_count, test_name);
		g_pass_count++;
		return ;
	}
	if (expected == NULL || actual == NULL)
	{
		printf(RED "✗ FAIL" RESET " [%d]: %s\n", g_test_count, test_name);
		printf("  Expected: %s\n", expected ? expected : "NULL");
		printf("  Got:      %s\n", actual ? actual : "NULL");
		return ;
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

void	test_multiple_fds(void)
{
	int		fd1, fd2, fd3;
	char	*line;

	print_test_header("Multiple File Descriptors");
	fd1 = open("test_fd1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd1, "FD1-Line1\n", 10);
	write(fd1, "FD1-Line2\n", 10);
	close(fd1);
	fd2 = open("test_fd2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd2, "FD2-Line1\n", 10);
	write(fd2, "FD2-Line2\n", 10);
	close(fd2);
	fd3 = open("test_fd3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd3, "FD3-Line1\n", 10);
	close(fd3);
	fd1 = open("test_fd1.txt", O_RDONLY);
	fd2 = open("test_fd2.txt", O_RDONLY);
	fd3 = open("test_fd3.txt", O_RDONLY);
	line = get_next_line(fd1);
	assert_string_equals("FD1-Line1\n", line, "Read first line from FD1");
	free(line);
	line = get_next_line(fd2);
	assert_string_equals("FD2-Line1\n", line, "Read first line from FD2");
	free(line);
	line = get_next_line(fd3);
	assert_string_equals("FD3-Line1\n", line, "Read first line from FD3");
	free(line);
	line = get_next_line(fd1);
	assert_string_equals("FD1-Line2\n", line, "Read second line from FD1");
	free(line);
	line = get_next_line(fd2);
	assert_string_equals("FD2-Line2\n", line, "Read second line from FD2");
	free(line);
	line = get_next_line(fd1);
	assert_string_equals(NULL, line, "FD1 EOF");
	line = get_next_line(fd2);
	assert_string_equals(NULL, line, "FD2 EOF");
	line = get_next_line(fd3);
	assert_string_equals(NULL, line, "FD3 EOF");
	close(fd1);
	close(fd2);
	close(fd3);
	unlink("test_fd1.txt");
	unlink("test_fd2.txt");
	unlink("test_fd3.txt");
}

void	test_interleaved_reads(void)
{
	int		fd1, fd2;
	char	*line;

	print_test_header("Interleaved Reads");
	fd1 = open("test_int1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd1, "A\nB\nC\n", 6);
	close(fd1);
	fd2 = open("test_int2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd2, "X\nY\nZ\n", 6);
	close(fd2);
	fd1 = open("test_int1.txt", O_RDONLY);
	fd2 = open("test_int2.txt", O_RDONLY);
	line = get_next_line(fd1);
	assert_string_equals("A\n", line, "FD1 first");
	free(line);
	line = get_next_line(fd2);
	assert_string_equals("X\n", line, "FD2 first");
	free(line);
	line = get_next_line(fd1);
	assert_string_equals("B\n", line, "FD1 second");
	free(line);
	line = get_next_line(fd2);
	assert_string_equals("Y\n", line, "FD2 second");
	free(line);
	line = get_next_line(fd1);
	assert_string_equals("C\n", line, "FD1 third");
	free(line);
	line = get_next_line(fd2);
	assert_string_equals("Z\n", line, "FD2 third");
	free(line);
	close(fd1);
	close(fd2);
	unlink("test_int1.txt");
	unlink("test_int2.txt");
}

void	test_many_fds(void)
{
	int		fds[10];
	char	*line;
	char	filename[20];
	char	content[20];
	int		i;

	print_test_header("Many File Descriptors (Stress Test)");
	i = 0;
	while (i < 10)
	{
		sprintf(filename, "test_many%d.txt", i);
		sprintf(content, "File%d-Line1\n", i);
		fds[i] = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		write(fds[i], content, strlen(content));
		close(fds[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		sprintf(filename, "test_many%d.txt", i);
		fds[i] = open(filename, O_RDONLY);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fds[i]);
		sprintf(content, "File%d-Line1\n", i);
		assert_string_equals(content, line, "Read from many FDs");
		free(line);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		close(fds[i]);
		sprintf(filename, "test_many%d.txt", i);
		unlink(filename);
		i++;
	}
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
	printf("║   Get Next Line - BONUS Test Suite    ║\n");
	printf("║   BUFFER_SIZE: %-5d                  ║\n", BUFFER_SIZE);
	printf("╚════════════════════════════════════════╝\n");
	test_multiple_fds();
	test_interleaved_reads();
	test_many_fds();
	print_summary();
	return (g_test_count == g_pass_count ? 0 : 1);
}
