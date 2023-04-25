#include "shell.h"
/**
 * _errors - handles errors
 * @pid: process ID
 * Return: no return
 */
void _errors(pid_t pid)
{
	if (pid == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
}
