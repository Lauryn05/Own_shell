#include "shell.h"
/**
 * builtin - Carries out built in commands
 * @args: Arguments passed through
 * @n: Number of arguments
 * Return: true if built in command, false otherwise
 */
bool builtin(char **args, size_t n)
{
	if (_strncmp(args[0], "exit", 4) == 0)
		_exits(args, n);
	else if ((_strncmp(args[0], "env", 3) == 0) ||
			(_strncmp(args[0], "printenv", 8) == 0) ||
			(_strncmp(args[0], "unsetenv", 8) == 0) ||
			(_strncmp(args[0], "setenv", 6) == 0))
	{
		envi(args, n);
		return (true);
	}
	return (false);
}
