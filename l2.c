#include "shell.h"
/**
 * list_len - size of the list
 * @head: head
 *
 * Return: size of list
 */
size_t list_len(const list_t *head)
{
	size_t i_it = 0;

	while (head)
	{
		head = head->next;
		i_it++;
	}
	return (i_it);
}

/**
 * list_to_strings - creat array of string
 * @head: hrad
 *
 * Return: array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i_it = list_len(head), j_it;
	char **strs;
	char *str;

	if (!head || !i_it)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (i_it + 1));
	if (!strs)
		return (NULL);
	for (i_it = 0; node; node = node->next, i_it++)
	{
		str = malloc(_strlen(node->string) + 1);
		if (!str)
		{
			for (j_it = 0; j_it < i_it; j_it++)
				free(strs[j_it]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->string);
		strs[i_it] = str;
	}
	strs[i_it] = NULL;
	return (strs);
}


/**
 * print_list - print
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->string ? head->string : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - _______________
 * @node: pointer to list head
 * @prefix: string to match
 * @c_char: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c_char)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->string, prefix);
		if (p && ((c_char == -1) || (*p == c_char)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
		{
			return (i);
		}
		head = head->next;
		i++;
	}
	return (-1);
}
