#include "shell.h"
/**
 * _myenv - prints working env wen called
 * @info - pointer to info_t struct
 * return 0 if success , 1 if faileure
 */
int _myenv(info_t *info)
{
	list_t *env = info->env /*get env variables linked list*/
	
	while (env != NULL)
	{
		_puts(env->str);
		_putchar("\n");

		env = env->next;
	}
	return 0;
}
/**
 * find_builtin - find and execute a built in command if recognized 
 *  @info: pointer to info_t struct
 *  return 0 if no built in found or 1 if successful
 */
int find_builtin(info_t *info)
{
	unsigned int  = 0;

	while (builtins[i].type != NULL)
	{
		if (_strcmp(info->argv[0], builtins[i].type) == 0)
		{
			/*call builtin function and pass the info struct*/
			int result = builtins[i].func(info);
			return result;
		}
		i++;
	}
	return 0;
}
