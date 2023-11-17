#include "shell.h"
/**
 * replace_vars - function that replace the vars
 * @info_: data type information
 *
 * Return: one or zero
 */
int replace_vars(info *info_)
{
	int i_it = 0;
	list_t *n;

	for (i_it = 0; info_->argvector[i_it]; i_it++)
	{
		if (info_->argvector[i_it][0] != '$' || !info_->argvector[i_it][1])
			continue;

		if (!_strcmp(info_->argvector[i_it], "$?"))
		{
			replace_string(&(info_->argvector[i_it]),
				_strdup(convert_number(info_->status_number, 10, 0)));
			continue;
		}
		if (!_strcmp(info_->argvector[i_it], "$$"))
		{
			replace_string(&(info_->argvector[i_it]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		n = node_starts_with(info_->env_data, &info_->argvector[i_it][1], '=');
		if (n)
		{
			replace_string(&(info_->argvector[i_it]),
				_strdup(_strchr_(n->string, '=') + 1));
			continue;
		}
		replace_string(&info_->argvector[i_it], _strdup(""));

	}
	return (0);
}

/**
 * is_chain - search of string about char
 * @info_: data type information
 * @buffer: the char buffer
 * @pointer_p: address to index
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info *info_, char *buffer, size_t *pointer_p)
{
	size_t byt = *pointer_p;

	if (buffer[byt] == '|' && buffer[byt + 1] == '|')
	{
		buffer[byt] = 0;
		byt++;
		info_->cmd_buf_type = 1;
	}
	else if (buffer[byt] == '&' && buffer[byt + 1] == '&')
	{
		buffer[byt] = 0;
		byt++;
		info_->cmd_buf_type = 2;
	}
	else if (buffer[byt] == ';') /* found end of this command */
	{
		buffer[byt] = 0; /* replace semicolon with null */
		info_->cmd_buf_type = 3;
	}
	else
		return (0);
	*pointer_p = byt;
	return (1);
}
