#include "monty.h"
/**
 * trim - removes the whitespaces from a line
 * @str: line from which to remove whitespaces
 * Return: char without whitespaces
 */
char *trim(char *str)
{
	size_t len = strlen(str);
	size_t start = 0;
	size_t end = len - 1;
	size_t i;

	while (start < len && isspace(str[start]))
	{
		start++;
	}
	while (end > start && isspace(str[end]))
	{
		end--;
	}

    /* Shift the characters to the beginning of the string */
    for (i = 0; i <= end - start; i++)
    {
        str[i] = str[start + i];
    }

    /* Add null-terminating character */
    str[i] = '\0';

    return str;
}
