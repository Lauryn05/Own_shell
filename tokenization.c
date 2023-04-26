#include "shell.h"
/**
 * tokenization - seperates strings into commands and arguments
 * @str: string to be seperated
 * @delim: seperator
 * @counter: number of words
 * Return: Pointers to string
 */
char **tokenization(char *str, char *delim, size_t *counter)
{
	int ch, vector;
	char **words, *ptr_st = str;
	int n, size[MAX_WORD];

	zeros(size, MAX_WORD);
	n = strcount(str, delim, size);
	if (n == 0)
		return NULL;
	words = malloc((sizeof(char *) * n) + 1);
	if (!words)
		return NULL;
	for (vector = 0; vector < n; vector++)
	{
		words[vector] = malloc((sizeof(char) * size[vector] + 1));
		if (!words[vector])
		{
			for (vector--; vector >= 0; vector--)
				free(words[vector]);
			free(words);
			return(NULL);
		}
		for (ch = 0; ch < size[vector]; ch++, ptr_st++)
		{
			while (delimiter(*ptr_st, delim))
				ptr_st++;
			words[vector][ch] = *ptr_st;
		}
		words[vector][ch] = '\0';
	}
	*counter = n;
	words[vector] = NULL;
	return (words);
}

