#include "monty.h"
/**
 * free_stack - frees memory used by stack
 * @top: pointer to first element of the stack
 * Return: nothing
 */

void free_stack(stack_t **top)
{
	stack_t *current = *top;
	stack_t *temp;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*top = NULL;
}
