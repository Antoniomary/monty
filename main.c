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
