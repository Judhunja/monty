#include "monty.h"
/**
 * is_line_empty - checks if a line is empty
 * @line: pointer to line to check
 * Return: always 0 (Success)
 */
int is_line_empty(char *line)
{
	while (*line != '\0')
	{
		if (!isspace(*line))
			return (0);
		line++;
	}
	return (1);
}
