#include "shell.h"
/**
 * free_info - Frees memory allocated in the info_t struct
 * @info - Pointer ro info struct containing cmd info
 * @free_argv - Flag to indicate whether to free the argv array
 */
void free_info(info_t *info, int free_argv)
{
	int i;

	if (info->arg)
	{
		free(info->arg);
		info->arg = NULL;
	}
	if (free_argv && info->argv)
	{
		for (i = 0; i<= info->argc; i++)
		{
			if (info->argv[i])
				free(info->argv[i])
		}
		free(info->argv);
		info->argv = NULL;
	}
}
