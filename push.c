#include "monty.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * push - pushes an element to the top of the stack
 * @top: top of the stack
 * @line_no: line no where the command is found
 * Return: nothing
 */
void push(stack_t **top, unsigned int line_no, char *value)
{
	stack_t *newnode;

	int n;
	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_no);
		free_stack(top);
		exit(EXIT_FAILURE);

	}

	n = atoi(value);
	if (n == 0 && strcmp(value, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_no);
		free_stack(top);
		exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	newnode->n = n;
	newnode->prev = NULL;
	
	newnode->next = *top;
	if (*top != NULL)
	{
		(*top)->prev = newnode;
	}
	*top = newnode;


}

void exec_comm(char *command, char *value, stack_t **top, unsigned int line_no)
{
	instruction_t comm_array[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};

        int i;

        for (i = 0; comm_array[i].opcode != NULL; i++)
        {
                if (strcmp(comm_array[i].opcode, command) == 0)
                {
                        comm_array[i].f(top, line_no, value);
                        return;
                }
        }
        fprintf(stderr, "L%u: unknown instruction %s\n",
line_no, command);
        exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	FILE *f_file = fopen(argv[1], "r");
	char *line = NULL;
	size_t line_len = 0;
	ssize_t lineread;
	unsigned int line_no = 1;
	char *command;
	stack_t *top = NULL;
	char *value = NULL;

	if (argc != 2)
	{
        	fprintf(stderr, "USAGE: monty file\n");
        	exit(EXIT_FAILURE);
	}

	if (f_file == NULL)
	{
        	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        	exit(EXIT_FAILURE);
	}

        while ((lineread = getline(&line, &line_len, f_file)) != -1)
        {
                line[strcspn(line, "\n")] = '\0';

                command = strtok(line, " ");
                value = strtok(NULL, " ");


                if (command == NULL)
                {
                        fprintf(stderr, "L%u: unknown instruction %s\n", line_no, command);
                        exit(EXIT_FAILURE);
                }
		exec_comm(command, value, &top, line_no);
		line_no++;
	}
        fclose(f_file);
	free(line);
	free_stack(&top);

        return (0);

}
