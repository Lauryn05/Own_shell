#include "shell.h"
/**
 * filestats - checks existance of file
 * @pathname: file path
 * @statsbuffer: Stores file info if fount
 * Return: true if it exists, false otherwise
 */
bool filestats(char *pathname, struct stat *statsbuffer)
{
	int rtn_stats;

	rtn_stats = stat(pathname, statsbuffer);
	if (rtn_stats == 0)
		return (true);
	return (false);
}
