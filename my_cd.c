/**
 * _mycd - built in that prints working directory
 * @info - pointer to info_t struct
 * return 1 if failure 0 if success
 */
#include "shell.h"
#include <pwd.h>

int _mycd(info_t *info)
{
    	char *target_dir = info->argc > 1 ? info->argv[1] : _getenv(info, "HOME");
	char current_dir[PATH_MAX];
	/*handle cd - to switch to previous directory*/
 	if (strcmp(target_dir, "-") == 0)
    	{
        	char *prev_dir = _getenv(info, "OLDPWD");
        	if (prev_dir == NULL)
        	{
            		_eputs("cd: OLDPWD not set\n");
            		return 1; 
        	}
        	target_dir = prev_dir;
    	}

    	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
    	{
		perror("cd");
        	return 1;
    	}

    	if (_setenv(info, "OLDPWD", current_dir) == -1)
    	{
        	perror("setenv");
        	return 1; 
    	}

    	if (chdir(target_dir) == -1)
    	{
        	perror("cd");
        	return 1; 
    	}	

    	if (_setenv(info, "PWD", target_dir) == -1)
    	{
        	perror("setenv");
        	return 1;
    	}
    	return 0;
}

