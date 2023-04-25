#include "shell.h"
/**
 * envi - Carries out env built in command
 * @args: Arguments passed
 * @n: Number of arguments
 * Return: No return
 */
void envi(char **args, size_t n)
{
	if (!args[1])
		_printenv();
	free_vector(args, n);
}
