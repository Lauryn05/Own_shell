#include "shell.h"
/**
 * _filepath - handles PATH
 * @filename: name of file
 * @statsbuffer: storage of file info if found
 * Return: file path or NULL if it is not find
 */
char *_filepath(char *filename, struct stat *statsbuffer)
{
	size_t s, n;
	char *fpath, *cpath = _getenv("PATH");
	char **paths = tokenization(cpath, ":", &n);

	for (s = 0; s < n; s++)
	{
		fpath = strs_con(3, paths[s], "/", filename);
		if (filestats(fpath, statsbuffer))
		{
			free_vector(paths, n);
			return (fpath);
		}
	}
	free_vector(paths, n);
	free(fpath);
	return (NULL);
}
