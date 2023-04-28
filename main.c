#include "shell.h"
/**
 * main - runs shell commands
 * @argc: Number of arguments
 * @argv: Array of arguments
 * @env: Enviromnet variable
 * Return: Always 0
 */
char **envt = NULL;
int main(int argc, char *argv[], char **env)
{
	char *c = NULL, *fullpath = NULL,
	     *prompt = "$ ", *buffer = NULL;
	ssize_t size;
	size_t buffer_size = 0, n;
	pid_t cpid;
	int cstat;
	bool pipe = false;
	struct stat statsbuffer;
	char **args, *bpointer;

	while (argc > 0)
	{
		if (!c)
		{
			if (isatty(STDIN_FILENO) == 0)
				pipe = true;
			if (!pipe)
				write (STDOUT_FILENO, prompt, 2);
			size = getline(&buffer, &buffer_size, stdin);
			if (size == 0)
			{
				perror("Error (getline)");
				free(buffer);
				exit(EXIT_FAILURE);
			}
			if (buffer[size - 1] == '\n')
				buffer[size - 1] = '\0';
			if (size == -1)
			{
				write(STDERR_FILENO, argv[0], _strlen(argv[0]));
				perror(": 1");
				free(buffer);
				exit(EXIT_FAILURE);
			}
		}
		if (!bpointer)
			bpointer = buffer;
		args = tokenization(buffer, " ", &n);
		if (builtin(args, n))
			continue;
		if (!filestats(args[0], &statsbuffer))
		{
			if (!fullpath)
			{
				write(STDERR_FILENO, argv[0], _strlen(argv[0]));
				perror(": 1");
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
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			perror(": 1");
			free_vector(args, n);
			exit(EXIT_FAILURE);
		}
		if (cpid == 0)
			exe(args, n, env);
		if (waitpid(cpid, &cstat, 0) == -1)
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			perror(": 1");
			free_vector(args, n);
			exit(EXIT_FAILURE);
		}
		free_vector(args,n);
	}
	free(buffer);
	return (0);
}
