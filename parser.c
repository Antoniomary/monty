#include "monty.h"

/**
 * parser - a function that executes the right function for the right opcode.
 * @head: a double pointer to head node of the stack.
 * @instr: the opcode.
 * @line_number: the line the opcode was passed.
 *
 * Return: 1 if opcode was found, else 0.
 */
int parser(stack_t **head, const char *instr, unsigned int line_number)
{
	instruction_t list[] = {
		{"push", push}, {"pall", pall},
		/* {"pint", pint}, {"pop", pop}, */
		/* {"swap", swap}, {"add", add}, */
		/* {"nop", nop}, {"sub", sub}, */
		/* {"div", div}, {"mul", mul}, */
		/* {"mod", mod}, */
		{NULL, NULL}
	};
	unsigned int i;

	for (i = 0; list[i].opcode; ++i)
		if (strcmp(list[i].opcode, instr) == 0)
		{
			(list[i].f)(head, line_number);
			return (0);
		}

	print_err(*head, "unknown instruction ", line_number, (char *) instr);

	return (1);
}
