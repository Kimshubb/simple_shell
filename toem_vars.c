#include "shell.h"
/**
 * is_chain - checks if the command contains a logical operator
 * @info - pointer to info_t struct containing the command info
 * @opstr - string containing the logical operators to check for ie &&,||
 * @opindex - pointer to a size_t variable to store index of the operator
 * Returns:
 *   - CMD_AND (2) if && oparator is found
 *   - CMD_OR (1) IF || OPERATOR IS FOUND
 *   - CMD_NORM (0)if none is found
 */
int is_chain(info_t *info, char *opstr, size_t *opindex)
{
	char *op;
	/*check if 1st arg of the cmd starts with a logical operator*/
	if (info->argv && info->argv[0] && opstr && (op = starts_with(opstr, info->argv[0])))
	{
		if (opindex)
			*opindex = op -opstr + 1;
		if (*op == '&' && op[1] == '&' && op[2] == '\0')
			return CMD_AND;
		else if (*op == '|' && op[1] == '|' && op[2] == '\0')
			return CMD_OR;
	}
	return CMD_NORM;
}
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
