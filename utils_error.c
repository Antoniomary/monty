#include "monty.h"

/**
 * check_arg_number - a function that checks if command line argument is two.
 * @argc: the number of arguments passed at command line.
 */
void check_arg_number(int argc)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "%s", err_colour);
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * malloc_error - a function that outputs error message for failed allocation,
 * frees memory, and exits with failure.
 * @head: a double pointer to head node of the stack.
 */
void malloc_error(stack_t *head)
{
	dprintf(STDERR_FILENO, "Error: malloc failed\n");
	free_stack(head);
	close(info.fd);
	exit(EXIT_FAILURE);
}

/**
 * print_err - a function that help the opcode functions print their unique
 * error messages, frees memory, and exits with failure code.
 * @head: a double pointer to head node of the stack.
 * @msg: the unique error message.
 * @line: the line number the opcode was passed.
 * @more: additional message to print.
 */
void print_err(stack_t *head, const char *msg, unsigned int line, char *more)
{
	dprintf(STDERR_FILENO, "L%u: %s%s\n", line, msg, more ? more : "");
	free_stack(head);
	close(info.fd);
	exit(EXIT_FAILURE);
}
