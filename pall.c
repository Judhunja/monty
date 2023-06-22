#include "monty.h"
/**
 * pall - prints all the elements of the stack
 * @top: pointer to top of stack
 * @line_no: line number where command is found
 * Return: nothing
 */
void pall(stack_t **top, unsigned int line_no, char *value)
{
	stack_t *ptr = *top;

	(void)line_no;

	(void)value;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}

}
