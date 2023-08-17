#include "shell.h"
/**
 * _mysetenv - initialize or modify the current environment
 * @info- pointer to info_t struct
 * return 0 - when a success 1 if a failure
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Usage: setenv VARIABLE VALUE\n");
		return 1;
	}
	/*set env variable using given args*/
	if (setenv(info->argv[1], info->argv[2], 1) == -1)
	{
		perror("Error setting Environment Variable");
		return 1;
	}
	return 0;
}

/**
 * _myunsetenv - remove environment variable
 * @info - pointer to info_t struct
 * return 0 - if successful 1 if a failure
 */
int _myunsetenv(info_t *info)
{
	if (info->argc != 2)
	{
		_eputs("Usage: unsetenv VARIABLE");
		return 1;
	}
	/*unset env variable using given args*/
	if (unsetenv(info->argv[1]) == -1)
	{
		perror("Error unsetting environment variable\n");
		return 1;
	}
	return 0;
}
