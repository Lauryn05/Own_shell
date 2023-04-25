#include "shell.h"
/**
 * _strncmp - compares first n characters of 2 string
 * @s1: String 1
 * @s2: String 2
 * @n: Number of characters to be compared
 * Return: -ve, +ve or 0
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t a;
	int d;

	for (a = 0; a < n; a++)
	{
		d = s1[a] - s2[a];
		if (d > 0 || d < 0)
			return (d);
	}
	return (0);
}
