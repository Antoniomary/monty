#include "monty.h"

/**
 * open_file - a functuin that opens a file.
 * @file: the file to be opened.
 *
 * Return: the file descriptor of the opened file.
 */
int open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s", file);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
