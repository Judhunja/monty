#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @top: top of the stack
 * Return: nothing
 */
void add(stack_t **top, unsigned int line_no, char *value)
{
	int a = 0;
	int b = 0;
	int sum = 0;
	stack_t *current = *top;
	stack_t *nxt = (*top)->next;

	(void)value;
	if (nxt == NULL || current == NULL)
	{
        	fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
        	exit(EXIT_FAILURE);
	}

	a = current->n;
	b = nxt->n;
	
	sum = a + b;

	nxt->n = sum;

	nxt->prev = NULL;
	*top = nxt;
}
