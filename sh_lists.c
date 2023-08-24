#include "shell.h"
/**
 * node_starts_with - find first node that starrts with a specified prefix
 * @list - pointer to the linked list
 * @prefix - delimiter character
 * returns - pointer to the first node that starts with the specified prefix
 * or null if none is found
 */
list_t *node_starts_with(list_t *list, char *prefix, char delim)
{
	while (list)
	{
		if (starts_with(list->str, prefix) && list->str[_strlen(prefix] == delim))
			return list;
		list = list->next;
	}
	return NULL;
}

/**
 * add_node - add a new node to beginning of linked list
 * @head - pointer to the head of a linked list
 * @str - str to be added to the new node
 * @num - numeric value associated with new node
 * return - pointer to newly added node
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return NULL;

	new_node->str = _strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return NULL;
	}
	new_node->num = num;
	new_node->next = *head;
	*head = new_node;

	return new_node;
}
