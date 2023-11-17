#include "shell.h"

/**
 * unset_alias - ereaes .the alias from the data information
 * @info_: data type information.
 * @string: alias.
 *
 * Return: 0 or 1 refare to error or one .
 */
int unset_alias(info *info_, char *string)
{
	char *p, c;
	int ret;

	p = _strchr_(string, '=');
	if (!p)
	{
		return (1);
	}
	c = *p;
	*p = 0;

	ret = delete_node_at_index(&(info_->alias),

	get_node_index(info_->alias, node_starts_with(info_->alias, string, -1)));

	*p = c;
	return (ret);
}

/**
 * _alias - _______________________________________
 * @info_: ______________________________________
 *         to maintain constant function prototype.
 *  Return: Always 0 .
 */
int _alias(info *info_)
{
	int i_itreator = 0;
	char *p = NULL;
	list_t *n = NULL;

	if (info_->argcounter == 1)
	{
		n = info_->alias;
		while (n)
		{
			print_alias(n);
			n = n->next;
		}
			return (0);
	}
		for (i_itreator = 1; info_->argvector[i_itreator]; i_itreator++)
		{
			p = _strchr_(info_->argvector[i_itreator], '=');
			if (p)
			{
				set_alias(info_, info_->argvector[i_itreator]);
			}
			else
				print_alias(node_starts_with(info_->alias, info_->argvector[i_itreator],
				 '='));
		}

		return (0);
}
/**
 * _myhistory - print the hestory
 * @info_: data type information
 *  Return: zero
 */
int _myhistory(info *info_)
{
	print_list(info_->history);
	return (0);
}

/**
 * _myalias - man alias
 * @info_: data type information
 *  Return: Always zero
 */
int _myalias(info *info_)
{
	int i_it = 0;
	char *string = NULL;
	list_t *n = NULL;

	if (info_->argcounter == 1)
	{
		n = info_->alias;
		while (n)
		{
			print_alias(n);
			n = n->next;
		}
		return (0);
	}
	for (i_it = 1; info_->argvector[i_it]; i_it++)
	{
		string = _strchr_(info_->argvector[i_it], '=');
		if (string)
			set_alias(info_, info_->argvector[i_it]);
		else
			print_alias(node_starts_with(info_->alias, info_->argvector[i_it], '='));
	}

	return (0);
}
