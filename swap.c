#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @top: first element
 * Return: nothing
 */
void swap(stack_t **top, unsigned int line_no, char *value)
{
	stack_t *current = *top;
	stack_t *nxt = (*top)->next;

	(void)value;

	if (nxt == NULL || current == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	nxt->prev = NULL;
	current->next = nxt->next;
	current->prev = nxt;
	nxt->next = current;

	if (current->next != NULL)
		current->next->prev = current;
	*top = nxt;
}
