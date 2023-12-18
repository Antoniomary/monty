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

	if (info.mode == QUEUE)
	{
		if ((*head)->next->n == 0)
			print_err(*head, err_msg_zero_div, line_number, NULL);

		(*head)->n %= (*head)->next->n;
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		return;
	}
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

/**
 * rotl - a function that rotates the stack to the top.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 *
 * Description: The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one.
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp = info.top;

	(void) line_number;

	if (*head && (*head)->next)
	{
		info.top = info.top->prev;
		info.top->next = NULL;

		temp->next = *head;
		temp->prev = NULL;
		(*head)->prev = temp;

		*head = temp;
	}
}

/**
 * rotr - a function that rotates the stack to the bottom.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 *
 * Description: The last element of the stack becomes the top element of the
 * stack.
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	(void) line_number;

	if (*head && (*head)->next)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;

		info.top->next = temp;
		temp->prev = info.top;
		temp->next = NULL;

		info.top = info.top->next;
	}
}
