#include "shell.h"
/**
 * setup_path - locates executable files for external commands
 * @info_t *info - pointer to info struct
 * return - void
 */
void setup_path(info_t *info)
{
	char *path_env = _getenv(info, "PATH");

	if (path_env != NULL)
	{
		/*TOKENIZE THE patH USING : As delimiter */
		char **path_dirs = strtow(path_env, ":");

		if (path_dirs != NULL)
		{
			/*use the first directory in PATH as the default*/
			info->path = path_dirs[0];
			/*free the dynamically allocated path directories*/
			free(path_dirs)
		}
	}
}
