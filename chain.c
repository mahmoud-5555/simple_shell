#include "shell.h"

/**
 * s_chain - tests if current char in buffer is a chain delimeter.
 * @info:  parameter struct.
 * @buff: char buffer.
 * @p: the address of current position in buffer.
 *
 * Return: 1 if chain delimeter, 0 otherwise .
 */
int s_chain(info_t *info, char *buff, size_t *p)
{
	size_t j = *p;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;
		j++;
		info->cmd_buff_type = CMD_AND;
	}
	else if (buff[j] == ';') /* found end of this command */
	{
		buff[j] = 0; /* replace semicolon with null */
		info->cmd_buff_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status.
 * @info: parameter struct.
 * @buff: the char buffer.
 * @p: address of current position in buffer.
 * @i: starting position in buffer.
 * @len: length of buffer.
 *
 * Return: Void
 */
void chek_chain(info_t *info, char *buff, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buff_type == CMD_AND)
	{
		if (info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buff_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * re_alias - replaces an aliases in the tokenized string.
 * @info: parameter struct.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int re_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * re_vars - replaces vars in the tokenized string.
 * @info: parameter struct.
 *
 * Return: 1 if replaced, 0 otherwise
 */
int re_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			re_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			re_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			re_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		re_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * re_string - replaces string.
 * @old: the address of old string.
 * @new: new string.
 *
 * Return: 1 if replaced, 0 otherwise
 */
int re_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
