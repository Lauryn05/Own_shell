#include "shell.h"
/**
 * strcount - counts the number of strings specified by delimiter
 * @str: String to be checked
 * @delim: Seperator
 * @array: points to array where the string length will be stored
 * Return: Number of strings
 */
int strcount(char *str, char *delim, int *array)
{
	unsigned int a, b, len = 1, counter = 0;
	char *_strcopy = str;
	bool begin = false, sep;

	if (!begin)
		for (b = 0; delim[b]; b++)
		{
			if (*_strcopy == delim[b])
				_strcopy++;
			else
				begin = true;
		}
	if (!*(_strcopy + 1))
		return (1);
	for (a = 1; _strcopy[a]; a++)
	{
		sep = delimiter(_strcopy[a], delim);
		if (sep && !(delimiter(_strcopy[a - 1], delim)))
		{
			array[counter] = len;
			counter++;
		}
		if ((!_strcopy[a + 1]) && !sep)
		{
			len++;
			array[counter] = len;
			counter++;
			break;
		}
		if (!sep)
			len++;
		else
			len = 0;
	}
	return (counter);
}
