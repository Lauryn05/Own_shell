#include "shell.h"
/**
 * strs_con - concatenates two or more strings to new array
 * @n: Number of strings to be joined
 * @s1: String 1
 * @s2: String 2
 * Return: Pointer to allocated memory containing concatenated string
 */
char *strs_con(int n, char *s1, char *s2, ...)
{
	int a, b, c = 0, len = 0;
	char *str, *join;
	va_list args_m, args_c;

	if (!s1 || !s1[0])
		len = 1;
	else
		len = len + _strlen(s1);
	if (!s2 || !s2[0])
		len++;
	else
		len = len + _strlen(s2);
	if (n > 2)
	{
		va_start(args_m, s2);
		va_copy(args_c, args_m);
		for (a = 0; a < (n - 2); a++)
		{
			str = va_arg(args_m, char *);
			len = len + (!str || !str[0]) ? 1 : _strlen(str);
		}
		va_end(args_m);
	}
	join = malloc((sizeof(char) * len) + 1);
	if (!join)
		return (NULL);
	if (s1)
		for (a = 0; s1[a]; a++, c++)
			join[c] = s1[a];
	if (s2)
		for (a = 0; s2[a]; a++, c++)
			join[c] = s2[a];
	if (n > 2)
	{
		va_start(args_m, s2);
		for (b = 0; b < (n - 2); b++)
		{
			str = va_arg(args_m, char *);
			for (a = 0; str[a]; a++, c++)
				join[c] = str[a];
		}
		va_end(args_m);
		va_end(args_c);
	}
	return (join);
}
