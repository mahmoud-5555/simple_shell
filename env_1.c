#include "shell.h"

/**
 * get_environ - function that deal with environ
 * @info_: information data
 * Return:0
 */
char **get_environ(info *info_)
{
	if (!info_->environ || info_->env_changed)
	{

		info_->environ = list_to_strings(info_->env_data);

		info_->env_changed = 0;

	}

	return (info_->environ);
}

/**
 * _unsetenv - remove the data
 * @info_: data type infromation
 *  Return: one  or zero
 * @string: the string env string property
 */
int _unsetenv(info *info_, char *string)
{
	list_t *node = info_->env_data;
	size_t i = 0;
	char *p;

	if (!node || !string)
	{
		return (0);
	}
	while (node)
	{
		p = starts_with(node->string, string);
		if (p && *p == '=')
		{
			info_->env_changed = delete_node_at_index(&(info_->env_data), i);
			i = 0;
			node = info_->env_data;
			continue;
		}
		node = node->next;
		i++;
	}

	return (info_->env_changed);
}

/**
 * _setenv - new env_data
 * @info_: information data type
 * @string: env_string
 * @value: str_env_value
 *  Return: -->> zero
 */
int _setenv(info *info_, char *string, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *p;

	if (!string || !value)
		return (0);

	buffer = malloc(_strlen(string) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, string);
	_strcat_(buffer, "=");
	_strcat_(buffer, value);
	node = info_->env_data;
	while (node)
	{
		p = starts_with(node->string, string);
		if (p && *p == '=')
		{
			free(node->string);
			node->string = buffer;
			info_->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info_->env_data), buffer, 0);
	free(buffer);
	info_->env_changed = 1;
	return (0);
}
