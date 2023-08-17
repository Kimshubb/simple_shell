/*
 *
 *
 *
*/
char *_getenv(info_t *info, const char *name)
{
	list_t *env = info->env;

	while (env != NULL)
	{
		if (_strcmp(env->str, name) == 0)
			return strchr(env->str, "=") + 1;/*return value after 1*/
		env = env->next;
	}
	return NULL; /*ENV VARIABLE NOT FOUND*/
}
