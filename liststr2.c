#include "shell.h"

/**
 * list_len - determines length of linked list.
 * @k: pointer to first node.
 *
 * Return: size of list.
 */
size_t list_len(const list_t *k)
{
	size_t i = 0;

	while (k)
	{
		k = k->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str.
 * @k: pointer to first node.
 *
 * Return: array of strings.
 */
char **list_to_strings(list_t *k)
{
	list_t *node = k;
	size_t i = list_len(k), j;
	char **strs;
	char *str;

	if (!k || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list.
 * @k: pointer to first node.
 *
 * Return: size of list.
 */
size_t print_list(const list_t *k)
{
	size_t i = 0;

	while (k)
	{
		_puts(convert_number(k->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(k->str ? k->str : "(nil)");
		_puts("\n");
		k = k->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix.
 * @node: pointer to the list head.
 * @prefix: string to match.
 * @c: next character after prefix to match.
 *
 * Return: match node or null.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets index of a node.
 * @k: pointer to list head.
 * @node: pointer to the node.
 *
 * Return: index of node or -1 .
 */
ssize_t get_node_index(list_t *k, list_t *node)
{
	size_t i = 0;

	while (k)
	{
		if (k == node)
			return (i);
		k = k->next;
		i++;
	}
	return (-1);
}
