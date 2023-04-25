#include "shell.h"
/**
 * _exits - carries out the exit built in command
 * @args: Arguments passed through
 * @n: Number of arguments
 * Return: No return
 */
void _exits(char **args, size_t n)
{
	int stat = EXIT_SUCCESS;

	if (args[1])
		stat = _atoi(args[1]);
	free_vector(args, n);
	exit(stat);
}
