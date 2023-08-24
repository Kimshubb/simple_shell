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
/**
 * clear_info - clears the info struct
 * @info -struct being cleared
 * return 1 success
 * 	  0 if failure
 */
void clear_info(info_t *info)
{
	if (info->args != NULL)
	{
		free(info->args);
		info->args = NULL;
	}
	if (info->argv != NULL)
	{
		free_info((void **)info->argv);
		info->argv = NULL;
	}
	info->arg = NULL;
    	info->path = NULL;
    	info->argc = 0;
    	info->line_count = 0;
    	info->err_num = 0;
    	info->linecount_flag = 0;
   	info->fname = NULL;
 	info->env = NULL;
    	info->history = NULL;
    	info->alias = NULL;
    	info->env_changed = 0;
    	info->status = 0;
    	info->cmd_buf = NULL;
    	info->cmd_buf_type = CMD_NORM;
    	info->readfd = 0;
    	info->histcount = 0;
}
/**
 * _memmove - move from source to prefreed destination
 * @dest - where to move
 * @src - source
 * return 1 if operation successful
 */
void *_memmove(void *dest, const void *src, size_t n)
{
	char *d = (char *)dest;
	const char *s = (const char *)src;
	size_t i = 0;

	if (d < s)
	{
		for (i = n; i < n; i++)
		{
			d[i] = s[i];
		}
		else
		{
			for (i = n; i >0; i--)
			{
				d[i-1] = s[i-1];
			}
		}
		return dest;

	}
}
