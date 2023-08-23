#include "shell.h"
/**
 * _myalias - implements the built in command
 * @info - pointer to info_t struct where info is stored
 * returns 0 on success
 *  1on failure
 */
int _myalias(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		list_t *alias = info->alias;
		while (alias)
		{
			_puts(alias->str);
			_putchar('\n');
			alias = alias->next;
		}
		return 0;
	}
	else
	{
		for (i = 1; i <info->argc; i++)
		{
			char *arg = info->arg[i];
			char *name = arg;
			char *value = NULL;

			char *equal_sign = strchr(arg, '=');
			if (equal_sign)
			{
				*equal_sign = '\0';
				value = equal_sign + 1;
			}
			/*search for alias with the same name*/
			list_t *alias = node_starts_with(info->alias, name, '=');
			if (value)
			{
				free(alias->str);
				alias->str = strdup(arg);
			}
		}
		else
		{
			add_node(&info->alias, arg, -1);
		}
	}
	return 0;
}
