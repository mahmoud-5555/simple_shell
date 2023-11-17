#include "shell.h"

/**
 * add_node - function that add node to linked_list
 * @head: the head of the linked list
 * @string: string value the new data
 * @index: node index
 *
 * Return: size of list
 */

list_t *add_node(list_t **head, const char *string, int index)
{
	list_t *new_head;

	if (!head)
	{
		return (NULL);
	}
	new_head = malloc(sizeof(list_t));
	if (!new_head)
	{
		return (NULL);
	}
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = index;
	if (string)
	{
		new_head->string = _strdup(string);
		if (!new_head->string)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - add node to the ind
 * @head: the_head
 * @string: string value
 * @index: node index
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *string, int index)
{
	list_t *new_node, *node;

	if (!head)
	{
		return (NULL);
	}

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
	{
		return (NULL);
	}
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = index;
	if (string)
	{
		new_node->string = _strdup(string);

		if (!new_node->string)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new_node;
	}
	else
	{
		*head = new_node;
	}
	return (new_node);
}
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
/**
 * print_list_str - print
 * @head: hrad
 *
 * Return: size_list
 */
size_t print_list_str(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->string ? head->string : "(nil)");

		_puts("\n");

		head = head->next;

		i++;
	}

	return (i);
}

/**
 * delete_node_at_index - <----------------
 * @head: head
 * @index: index
 * Return: 1 or 0
 */
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev;
	unsigned int i = 0;

	if (!head || !*head)
	{
		return (0);
	}

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->string);

		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev->next = node->next;
			free(node->string);

			free(node);

			return (1);
		}

		i++;

		prev = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees the list
 * @head__p: hrad
 *
 * Return: void
 */
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
void free_list(list_t **head__p)
{
	list_t *node, *next_node, *head = NULL;

	if (!(head) || !*head__p)
	{
		return;
	}

	head = *head__p;
	node = head;

	while (node)
	{
		next_node = node->next;

		free(node->string);

		free(node);
		node = next_node;
	}
	*head__p = NULL;
}
