#include "shell.h"
/**
 * _getenv - gets value of an environmental variable
 * @name: variable to look for
 * Return: pointer to the start index of the value
 */
char *_getenv(char *name)
{
	char **pt = envt;
	size_t len = _strlen(name);

	while (!*pt)
	{
		if (_strncmp(*pt, name, len) == 0 && (*pt)[len] == '=')
			return (&((*pt)[len + 1]));
		pt++;
	}
	return (NULL);
}
