#include "shell.h"
/**
 * exe - executes other processes
 * @arg:
 * @n:
 * @envp:
 * Return:
 */
int exe(char **arg, int n, char **envp)
{
	execve(arg[0], arg, envp);
	free_vector(arg, n);
	perror("Error (execve)");
	exit(EXIT_FAILURE);
}
