#include "shell.h"



/**
 * _getenv - function that re_out the _env_data from the list
 * @info_: data type information
 * @name: ________________________
 *
 * Return: the value
 */

char *_getenv(info *info_, const char *name)
{
	list_t *node = info_->env_data;
	char *p;

	while (node)
	{
		p = starts_with(node->string, name);
		{
			if (p && *p)
				return (p);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - ________________________________
 * @info_: data type "information"
 *  Return: 0
 */
int _mysetenv(info *info_)
{
	if (info_->argcounter != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info_, info_->argvector[1], info_->argvector[2]))
	{
		return (0);
	}
	return (1);
}

/**
 * _myunsetenv - rm _the_env
 * @info_: data type information
 *  Return: zero
 */
int _myunsetenv(info *info_)
{
	int i_it;

	if (info_->argcounter == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i_it = 1; i_it <= info_->argcounter; i_it++)
		_unsetenv(info_, info_->argvector[i_it]);

	return (0);
}

