#include "shell.h"
/**
 * zeros - sets all elements of an array to 0
 * @array: Array to be set
 * @size: Array size
 * Return: no return
 */
void zeros(int *array, size_t size)
{
	size_t a;

	for (a = 0; a < size; a++)
		array[a] = 0;
}
