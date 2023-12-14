#include "monty.h"

/**
 * add - a function adds the top two elements of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void add(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't add, stack too short";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	info.top->prev->n += info.top->n;
	free_second_top();
}
