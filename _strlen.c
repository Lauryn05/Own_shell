#include "shell.h"
/**
 * _strlen - measures length of a string
 * @s: String to be measured
 * Return: Length of string
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s +count) != '0')
		count++;
	return (count);
}
