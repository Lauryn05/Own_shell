#include "shell.h"
/**
 * exe - executes other processes
 * @arg: Arguments
 * @n: Number of arguments
 * @envp: Environment variable
 * Return: No return if successful or error on failure
 */
int exe(char **arg, int n, char **envp)
{
	execve(arg[0], arg, envp);
	free_vector(arg, n);
	perror("Error (execve)");
	exit(EXIT_FAILURE);
}
