#include "shell.h"
/**
 * free_vector - frees memory allocated to 2D array
 * @vector: vector to be freed
 * @len: Number of pointers in the vector
 * Return: No return
 */
void free_vector(char **vector, int len)
{
	int a;

	for (a = 0; a < len; a++)
		free(vector[a]);
	free(vector);
}
