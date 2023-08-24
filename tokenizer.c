/*
 * custom_strtok - basically tokenizes a string using a delimiter
 * @delim - delimiter string 
 * @saveptr - pointer to a saved pointer
 * returns - token
 */
#include "shell.h"

char *custom_strtok(char *str, const char *delim, char **saveptr)
{
	char *token = str;

 	if (!str && !*saveptr)
        	return NULL;
	/*skip leading delim characters by moving str ahead using strspn*/
    	if (!str)
        	str = *saveptr;
    		str += strspn(str, delim);
    	if (*str == '\0')
    	{
        	*saveptr = NULL;
        	return NULL;
    	}
	/*search for the next delim and replace with null terminator*/
    	str = strpbrk(token, delim);
    	if (str)
        	*str++ = '\0';
    	else
        	*saveptr = token + _strlen(token);
    	return token;
}

/**
 * custom_strtow - tokenizes a str based on provided delimiter
 * @str - str to be tokenized
 * @delim - delim string to split input
 * returns - array of pointers to the tokens
 */
char **custom_strtow(char *str, char *delim)
{
	char **tokens = NULL;
	char *token;
	int token_count = 0;

	if (!str || !delim)
		return NULL;
	tokens = malloc(sizeof(char *));
	if (!tokens)
		return NULL;
	tokens = custom_strtok(str, delim, NULL);
	while (token)
	{
		tokens[token_count] = token;
		token_count++;

		tokens = realloc(tokens. sizeof(char *) * (token_count + 1));
		if (!tokens)
			return NULL;
		token = custom_strtok(NULL, delim, NULL);
	}
	tokens[token_count] = NULL;
	return tokens;
}
