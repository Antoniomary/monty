#include "monty.h"

/**
 * free_stack - a function that frees a stack.
 * @head: a pointer to head node of the stack.
 */
void free_stack(stack_t *head)
{
	stack_t *temp = NULL;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * free_second_top - a function that frees the node under the top node.
 */
void free_second_top(void)
{
	stack_t *first_top = info.top;

	info.top = info.top->prev;
	free(first_top);
}
