#include "shell.h"
/**
 * starts_with checks if a string starts with a specified index
 * @str - the str being checked
 * @prefix -being checked
 * returns 1 if str starts with prefix checked 0 otherwise
 */
int starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
			return 0;
		prefix++;
		str++;
	}
	return 1;
}
/**
 * _strdup - duplicate a string
 * @str - the str to duplicate
 * returns a pointer to the newly allocated duplicated string
 */
char *_strdup(const char *str)
{
	char *dupl_str;
	size_t len, i;

	if (str == NULL)
		return NULL;
	len = _strlen(str);
	dup_str = malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
		return NULL;
	for (i = 0; i <=len; i++)
		dup_str[i] = str[i];
	return dup_str;
}

/**
 * replace_exit_status - handles the $? variable
 * @input - where to look for the variable
 * @exit_status - exit status convetrted to cint
 */
char *replace_exit_status(char *input, int exit_status)
{
	char exit_status_str[];
	int_to_str(exit_status, exit_status_str);

	return replace_substring(input, "$?", exit_status_str);
}
/**
 * repalce_process_id - handle $$ variable
 * @input - input to look for the var
 * return 1 if success
 */
char *replace_pid(char *input)
{
	char p_id_str[16];
	int_to_str(getpid(), p_id_str);

	return(replace_substring(input, "$$", p_id_str))
}
/**
 * _putchar - writes to std output
 * @c - the character to print
 * Returns 1 on success
 * On error -1 is returned and errno set appro
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
