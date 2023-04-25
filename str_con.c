#include "shell.h"
/**
 * str_con - concatenates two strings to new array
 * @s1: String 1
 * @s2: String 2
 * Return: Address of memory allocation containing concatinated string
 */
char *str_con(char *s1, char *s2)
{
	int a, b = 0, len1, len2;
	char *join;

	if (s1 == NULL || s1[0] == '\0')
		len1 = 1;
	else
		for (len1 = 0; s1[len1]; len1++)
			continue;
	if (s2 == NULL || s2[0] == '\0')
		len2 = 1;
	else
		for (len2 = 0; s2[len2]; len2++)
			continue;
	join = malloc((sizeof(char) * (len1 + len2)) + 1);
	if (!join)
		return (NULL);
	if (s1 != NULL)
		for (a = 0; s1[a]; a++, b++)
			join[b] = s1[a];
	if (s2 != NULL)
		for (b = 0; s2[a]; a++, b++)
			join[b] = s2[a];
	return (join);
}
