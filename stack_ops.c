#include "monty.h"

/**
 * push - a function that pushes an element to the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL;

	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error(*head);

	new->n = info.new_n;
	new->prev = NULL, new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		new->prev = info.top;
		info.top->next = new;
	}

	info.top = new;
}

/**
 * pall - a prints all the values on the stack, starting from the top of the
 * stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = info.top;

	(void) head, (void) line_number;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}

/**
 * pop - a function removes the top element of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = info.top;
	char *err_msg = "can't pop an empty stack";

	if (!temp)
		print_err(*head, err_msg, line_number, NULL);

	info.top = info.top->prev;
	info.top->next = NULL;
	free(temp); /* frees the top node */

}

/**
 * pint - a function that prints the value at the top of the stack
 * followed by a new line.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void pint(stack_t **head, unsigned int line_number)
{
	char *err_msg = "can't pint, stack empty";

	if (!info.top)
		print_err(*head, err_msg, line_number, NULL);

	printf("%d\n", info.top->n);
}

/**
 * swap - a function that swaps the top two elements of the stack.
 * @head: a double pointer to head node of the stack.
 * @line_number: the line the opcode was passed.
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;
	char *err_msg = "can't swap, stack too short";

	(void) head;

	if (!info.top || !info.top->prev)
		print_err(*head, err_msg, line_number, NULL);

	temp = info.top->n;
	info.top->n = info.top->prev->n;
	info.top->prev->n = temp;
}
