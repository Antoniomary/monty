#include "monty.h"

/**
 * add - a function that adds the top two elements of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	char *err_msg = "can't add, stack too short";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	if (info.mode == QUEUE)
	{
		(*head)->n += (*head)->next->n;
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		return;
	}
	info.top->prev->n += info.top->n;
	pop(head, line_number);
}

/**
 * sub - a function that subtracts the top element from the second
 * top element of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void sub(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't sub, stack too short";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	if (info.mode == QUEUE)
	{
		(*head)->n -= (*head)->next->n;
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		return;
	}
	info.top->prev->n -= info.top->n;
	pop(head, line_number);
}

/**
 * nop - a function that doesn’t do anything.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * _div - a function that divides the second top element of the stack
 * by the top element of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void _div(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't div, stack too short";
	char *err_msg_zero_div = "division by zero";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	if (info.mode == QUEUE)
	{
		if ((*head)->next->n == 0)
			print_err(*head, err_msg_zero_div, line_number, NULL);

		(*head)->n /= (*head)->next->n;
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		return;
	}
	if (info.top->n == 0)
		print_err(*head, err_msg_zero_div, line_number, NULL);

	info.top->prev->n /= info.top->n;
	pop(head, line_number);
}

/**
 * mul - a function that multiplies the top two elements of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void mul(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't mul, stack too short";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	if (info.mode == QUEUE)
	{
		(*head)->n *= (*head)->next->n;
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		return;
	}
	info.top->prev->n *= info.top->n;
	pop(head, line_number);
}
