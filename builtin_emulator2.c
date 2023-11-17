#include "shell.h"

/**
 * _history - function that display the history.
 *"hestory is  a linked list thats why i used print_list()".
 * @info_: the information data type.
 *  Return: zero.
 */
int _history(info *info_)
{

		print_list(info_->history);
		return (0);

}



/**
 * set_alias -function that put the alias on the string.
 * @info_: parameter struct.
 * @string:  string alias.
 *
 * Return: 0 or 1 refare to Error or scssed
 */
int set_alias(info *info_, char *string)
{
		char *p;

		p = _strchr_(string, '=');
		if (!p)
		{
			return (1);
		}
		if (!*++p)
			return (unset_alias(info_, string));

		unset_alias(info_, string);
		return (add_node_end(&(info_->alias), string, 0) == NULL);
}

/**
 * print_alias - "alias string".
 * @node: alias node.
 *
 * Return: 0 or 1 refare to Error or scssed
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;


	if (node)
	{
		p = _strchr_(node->string, '=');
		for (a = node->string; a <= p; a++)
		{
			_putchar(*a);
		}
		_putchar('\'');
	    _puts(p + 1);
		_puts("'\n");

		return (0);

	}
		return (1);
}

