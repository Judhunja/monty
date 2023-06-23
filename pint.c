#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @top: first element in the stack
 * Return: nothing
 */
void pint(stack_t **top, unsigned int line_no, char *value)
{
	stack_t *temp = *top;

	(void)value;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
