#include "monty.h"

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
 * reverse_doubly_list - a function that reverses a doubly linked list.
 * @head: a double pointer to head node of the stack.
 */
void reverse_doubly_list(stack_t **head)
{
	stack_t *current = *head, *tmp = NULL;

	while (current)
	{
		tmp = current->prev;
		current->prev = current->next;
		current->next = tmp;
		*head = current;
		current = current->prev;
	}
}
