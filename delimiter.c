#include "shell.h"
/**
 * delimiter - Checks for delimiter
 * @c: Char to be checked
 * @delim: string of characters to be compated
 * Return: True if delimiter, false otherwise
 */
bool delimiter(char c, char *delim)
{
	int a;

	for (a = 0; delim[a]; a++)
		if (c == delim[a])
			return (true);
	return (false);
}
