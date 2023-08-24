/*
 * get_env - get environ variable
 * @ where to look for cmds
 * return 1 if env variable found
 *	  0 if not found
 *
*/
char *_getenv(info_t *info, const char *name)
{
	list_t *env = info->env;

	while (env != NULL)
	{
		if (_strcmp(env->str, name) == 0)
			return _strchr(env->str, "=") + 1;/*return value after 1*/
		env = env->next;
	}
	return NULL; /*ENV VARIABLE NOT FOUND*/
}
