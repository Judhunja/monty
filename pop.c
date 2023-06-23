#include "monty.h"
/**
 * pop - removes the top element from the stack
 * @top: first element of the stack
 * Return: nothing
 */
void pop(stack_t **top, unsigned int line_no, char *value)
{
	stack_t *temp = *top;

	(void)value;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (temp->next != NULL)
		*top = (*top)->next;
	else
		*top = NULL;
}
