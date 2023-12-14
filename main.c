#include "monty.h"

/**
 * main - entry point to a monty interpreter program.
 * @ac: the argument count at command line.
 * @av: array of pointers to the arguments supplied at the command line.
 *
 * Return: always 0 (success).
 */
int main(int ac, char **av)
{
	int line_size, keep_reading = true;
	unsigned int line_number;
	char *line = NULL, *piece = NULL;
	stack_t *head = NULL;

	check_arg_number(ac);
	info.fd = open_file(av[1]);
	for (line_number = 1; keep_reading ; ++line_number, line = NULL)
	{
		line_size = readline(&line, info.fd);
		if (line_size == -1)
			malloc_error(head);
		if (line_size > 0)
		{
			piece = strtok(line, " \t\n");
			if (piece)
			{
				if (piece[0] == '#')
					nop(&head, line_number);
				else if (strcmp(piece, "push") == 0)
				{
					piece = strtok(NULL, " \t\n");
					if (piece && is_valid_number(piece))
					{
						info.new_n = atoi(piece);
						push(&head, line_number);
					}
					else
						print_err(head, "usage: push integer", line_number, NULL);
				}
				else if (parser(&head, piece, line_number))
					free(line), close(info.fd), exit(EXIT_FAILURE);
			}
		}
		else
			keep_reading = false;
		free(line);
	}
	free_stack(head), close(info.fd);
	return (0);
}

/**
 * is_valid_number - a function that checks if a string is made up of
 * only numbers.
 * @str: the string to check.
 *
 * Return: 1 if true else 0.
 */
int is_valid_number(char *str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;

	for ( ; str[i] && isdigit(str[i]); ++i)
		;

	return (str[i] == '\0');
}

/**
 * readline - a function that reads text from a file descriptor.
 * @line: pointer to hold the retrieved text.
 * @fd: the file descriptor.
 *
 * Return: the number of bytes read. -1 if malloc failed or 0 for EOF.
 */
int readline(char **line, int fd)
{
	static char *ptr, buf[N];
	static int byte_read;
	int i = 0, bufsize = N;
	char *temp = NULL;

	*line = malloc(sizeof(char) * N);
	if (*line == NULL)
		return (-1);

	do {
		if (byte_read <= 0)
		{
			byte_read = read(fd, buf, sizeof(buf));
			if (byte_read <= 0)
			{
				(*line)[i] = '\0';
				return (byte_read);
			}
			ptr = buf;
		}

		if (i >= bufsize - 1)
		{
			bufsize *= 2;
			temp = _realloc(*line, i, bufsize);
			if (!temp)
				return (-1);
			*line = temp;
		}

		(*line)[i++] = *ptr++;
		--byte_read;
	} while ((*line)[i - 1] != '\n');
	(*line)[i] = '\0';

	return (i);
}
