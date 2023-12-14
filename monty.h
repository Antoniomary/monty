#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 10
#define OPCODE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct extra - information needed to run the stack
 * @new_n: integer for a new node.
 * @fd: the file descriptor of the script that is been run.
 * @top: the tail node.
 *
 * Description: contains some information
 * for stack, queues, LIFO, FIFO
 */
typedef struct extra
{
	int new_n;
	int fd;
	stack_t *top;
} stack_d;

stack_d info;

int parser(stack_t **head, const char *instr, unsigned int line_number);

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);

/********************* UTILS_ERROR *******************************/
void check_arg_number(int argc);
void malloc_error(stack_t *head);
void print_err(stack_t *head, const char *msg, unsigned int line, char *more);


/********************* GETLINE FUNCTION **************************/
int readline(char **line, int fd);

int is_valid_number(char *str);

/********************* UTILS_IO **********************************/
int open_file(char *file);


void free_second_top(void);
void free_stack(stack_t *head);

/********************* UTILS_ALLOC *******************************/
void *_realloc(void *ptr, int old_size, int new_size);

#endif /* MONTY_H */
