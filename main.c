#include "shell.h"
/**
 * main - runs shell commands
 * @argc: Number of arguments
 * @argv: Array of arguments
 * @env: Environmental variable of current program
 * Return: Always 0
 */
char **envt = NULL;
int main(void)
{
	char *fullpath = NULL, *prompt = "$ ", **args, *buffer;
	size_t buffer_size = 0, n, size;
	pid_t cpid;
	int cstat;
	bool pipe = false;
	struct stat statsbuffer;

	while (1 && !pipe)
	{
		write (STDOUT_FILENO, prompt, 2);
		size = getline(&buffer, &buffer_size, stdin);
		if (size == SIZE_MAX)
		{
			perror("Error (getline)");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (buffer[size - 1] == '\n')
			buffer[size - 1] = '\0';
		args = tokenization(buffer, " ", &n);
		if (builtin(args, n))
			continue;
		if (!filestats(args[0], &statsbuffer))
		{
			if (!fullpath)
			{
				perror("Error (file status)");
				free_vector(args, n);
				continue;
			}
			else
			{
				free(args[0]);
				args[0] = fullpath;
			}
		}
		cpid = fork();
		if (cpid == -1)
		{
			perror("Error (fork)");
			free_vector(args, n);
			exit(EXIT_FAILURE);
		}
		if (cpid == 0)
			exe(args, n, envt);
		if (waitpid(cpid, &cstat, 0) == -1)
		{
			perror("Error (wait)");
			free_vector(args, n);
			exit(EXIT_FAILURE);
		}
		free_vector(args, n);
	}
	free(buffer);
	return (0);
}
