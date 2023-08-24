#include "shell.h"
/**
 * int_to_str - convert an integer to a string
 * @num - the integer to convert
 * @str - pointer to the string buffer to store the result
 */
void int_to_str(int num, char *sr)
{
	_snprintf(str, sizeof(str), "%d", num);
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
	size_t find_len = _strlen(find);
	size_t replace_len = _strlen(replace);
	size_t count = 0;
	char *p;

	/*count number of occurences of find and allocate mem for result*/
	for (p = (char *)str; (p = _strstr(p, find)) != NULL; ++p)
		++count;
	result = malloc(_strlen(str) + count * (replace_len - find_len) + 1);
	if (result == NULL)
		return NULL;
	p = result;
	while (*str)
	{
		if (_strstr(str, find) == str)
		{
			_strcpy(p, replace);
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
/**
 * _puts - print to std out
 * @str - string to be printed
 * return: the string 1 on success
 *
 */
void _puts(char *str)
{
	if (str)
	{
		while (*str)
		{
			_putchar(*str);
			str++;
		}
	}
}
/**
 * _strcpy - copies a string 
 * @dest - the destination
 * @src - the source
 * Return : pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

