#include "shell.h"
/**
 * _myexit - Built-in command to exit the shell
 * @info: The info_t structure containing shell information
 * Return: Always 1 to indicate the shell should exit
 */
int _myexit(info_t *info) 
{
	if (info->argc > 1) 
	{
        	int exit_status = _erratoi(info->argv[1]);
        	if (exit_status != -1)
		{
            		info->status = exit_status;
        	}
		else 
		{
            		print_error(info, "exit: numeric argument required");
            		info->status = 2; /*Invalid argument error*/
        	}
    	}
    
    /*Free allocated resources and perform cleanup as needed*/
    	exit(info->status); /*Exit the shell with the specified status*/
}
 
