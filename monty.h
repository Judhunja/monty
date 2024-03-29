#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <ctype.h>
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
        void (*f)(stack_t **stack, unsigned int line_number, char *value);
} instruction_t;

void push(stack_t **top, unsigned int line_no, char *value);
void exec_comm(char *command, char *value, stack_t **top, unsigned int line_no);
void pall(stack_t **top, unsigned int line_no, char *value);
void free_stack(stack_t **top);
void pop(stack_t **top, unsigned int line_no, char *value);
void pint(stack_t **top, unsigned int line_no, char *value);
void swap(stack_t **top, unsigned int line_no, char *value);
void add(stack_t **top, unsigned int line_no, char *value);
void sub(stack_t **top, unsigned int line_no, char *value);
void nop(stack_t **top, unsigned int line_no, char *value);
int is_line_empty(char *line);
char *trim(char *str);
#endif
