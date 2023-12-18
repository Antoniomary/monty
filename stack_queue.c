#include "monty.h"

/**
 * stack - sets the format fo the data to a stack (LIFO)
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void) line_number;

	if (info.mode == QUEUE)
	{
		info.top = *head;
		reverse_doubly_list(head);
	}

	info.mode = STACK;
}

/**
 * queue - sets the format fo the data to a queue (FIFO)
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void) line_number;

	if (info.mode == STACK)
	{
		info.top = *head;
		reverse_doubly_list(head);
	}

	info.mode = QUEUE;
}
