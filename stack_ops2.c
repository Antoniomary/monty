#include "monty.h"

/**
 * mod - a function that  computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void mod(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't mod, stack too short";
	char *err_msg_zero_div = "division by zero";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	if (info.top->n == 0)
		print_err(*head, err_msg_zero_div, line_number, NULL);

	info.top->prev->n %= info.top->n;
	pop(head, line_number);
}
