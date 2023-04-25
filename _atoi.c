#include "shell.h"
/**
 * _atoi - converts string to integer
 * @s: String to be converted
 * Return: The integer
 */
int _atoi(char *s)
{
	int num = 0, a = 1, final;

	if (*(s) == '\0')
		return (0);
	while (!(*s >= '0' && *s <= '9'))
	{
		if (*s == '-')
			a = a * -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	final = a * num;
	return (final);
}
