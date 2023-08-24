#include "shell.h"
/**
 * _strcmp - custom strcmp function
 * @s1 -string 1 to be compared
 * @s2 - string 2 to be compared with
 * return 1 if success
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (int)((unsigned char)*s1 - (unsigned char)*s2);
}
/**
 * _strstr - checks if needle starts with haystack 
 * @haystack - string being checked
 * @needle - substring to find
 * return address of next char of haystack or NULL
 */
char *_strstr(const char *haystack, const char needle)
{
	size_t needle_len = _strlen(needle);

	while (*haystack)
	{
		if (_strncmp(haystack, needle, needle_len) == 0)
		{
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}
/**
 * _strlen - length of a string
 * @str - the string 
 * return 1 if success
 */
size_t _strlen(const char *str)
{
	size_t len = 0;
	while (str[len])
	{
		len++;
	}
	return len;
}
/**
 * _eputs - prints to stderr
 * @str - string to printed
 * return 1 if success
 */
void _eputs(char *str)
{
	int i = 0; 

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _snprintf - custom snprintf function to generate formatted output to strings
 * @str - string
 * @size -
 * @format -
 * @...
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int printed = vsnprintf(str, size, format, args);
	va_end(args);
	return printed;
}
/**
 * _eputchar - writes the character c to stderr
 * @c the character to print
 * return 1 on Success
 * on error -1 is returned and err no set appropriately
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
