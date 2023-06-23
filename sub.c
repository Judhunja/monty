#include "monty.h"
/**
 * sub - subtracts the top element from the second top element
 * @top: pointer to top of stack
 * Return: nothing
 */
void sub(stack_t **top, unsigned int line_no, char *value)
{
	int a = 0;
	int b = 0;
	int res = 0;
	stack_t *current = *top;
	stack_t *nxt = (*top)->next;

	(void)value;
	if (nxt == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	a = current->n;
	b = nxt->n;

	res = b - a;

	nxt->n = res;
	nxt->prev = NULL;
	*top = nxt;

}
