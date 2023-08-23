#include "shell.h"
/**
 * int_to_str - convert an integer to a string
 * @num - the integer to convert
 * @str - pointer to the string buffer to store the result
 */
void int_to_str(int num, char *sr)
{
	snprintf(str, sizeof(str), "%d", num);
}

/**
 * replace_substring - replace a substring with another 
 * @str - the original string
 * @find -the substring to find and replace
 * @replace - the substring to replace with
 * returns - the new replaced string or NUll
 */
char *replace_substring(const char *str, const char *find, const char *replace)
{
	char *result;
	size_t find_len = strlen(find);
	size_t replace_len = strlen(replace);
	size_t count = 0;
	char *p;

	/*count number of occurences of find and allocate mem for result*/
	for (p = (char *)str; (p = strstr(p, find)) != NULL; ++p)
		++count;
	result = malloc(strlen(str) + count * (replace_len - find_len) + 1);
	if (result == NULL)
		return NULL;
	p = result;
	while (*str)
	{
		if (strstr(str, find) == str)
		{
			strcpy(p, replace);
			p += replace_len;
			str += find_len;
		}
		else
		{
			*p++ = *str++;
		}
	}
	*p = '\0';
	return result;

}
