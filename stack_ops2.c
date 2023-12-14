#include "monty.h"

/**
 * mod - a function that computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void mod(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't mod, stack too short";
	char *err_msg_zero_mod = "division by zero";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	if (info.top->n == 0)
		print_err(*head, err_msg_zero_mod, line_number, NULL);

	info.top->prev->n %= info.top->n;
	pop(head, line_number);
}

/**
 * pchar - a function that prints the char at the top of the stack
 * followed by a new line.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void pchar(stack_t **head, unsigned int line_number)
{
	char *err_range = "can't pchar, value out of range";
	char *err_empty = "can't pchar, stack empty";

	(void) head;

	if (*head == NULL)
		print_err(*head, err_empty, line_number, NULL);

	if (!(info.top->n >= 0 && info.top->n <= 127))
		print_err(*head, err_range, line_number, NULL);

	printf("%c\n", info.top->n);
}

/**
 * pstr - a function that prints the char at the top of the stack
 * followed by a new line.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp = info.top;

	(void) head;
	(void) line_number;

	while (temp && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->prev;
	}

	putchar('\n');
}
