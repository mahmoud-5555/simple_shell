#include "shell.h"
/**
 * check_chain - check_chain
 * @info_: data type information
 * @b: buffer
 * @p_BYTS: position in b
 * @i: stating in i
 * @q: length of b
 *
 * Return: NOTHING
 */
void check_chain(info *info_, char *b, size_t *p_BYTS, size_t i, size_t q)
{
	size_t j_BYTE = *p_BYTS;

	if (info_->cmd_buf_type == 2)
	{
		if (info_->status_number)
		{
			b[i] = 0;
			j_BYTE = q;
		}
	}
	if (info_->cmd_buf_type == 1)
	{
		if (!info_->status_number)
		{
			b[i] = 0;
			j_BYTE = q;
		}
	}


	*p_BYTS = j_BYTE;
}

/**
 * replace_string - replaces string
 * @old_string: address of old_string string
 * @new_string: new_string string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old_string, char *new_string)
{
	free(*old_string);
	*old_string = new_string;
	return (1);
}
/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info_: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info *info_)
{
	int i;
	list_t *node;
	char *p_BYTS;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info_->alias, info_->argvector[0], '=');
		if (!node)
			return (0);
		free(info_->argvector[0]);
		p_BYTS = _strchr_(node->string, '=');
		if (!p_BYTS)
			return (0);
		p_BYTS = _strdup(p_BYTS + 1);
		if (!p_BYTS)
			return (0);
		info_->argvector[0] = p_BYTS;
	}
	return (1);
}
