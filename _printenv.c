#include "shell.h"
/**
 * _printenv - prints environmental variable of current
 * Return: No return
 */
void _printenv(void)
{
	int en_var;

	for (en_var = 0; envt[en_var]; en_var++)
		printf("%s\n", envt[en_var]);
}
