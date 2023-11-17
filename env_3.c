#include "shell.h"

/**
 * _myenv - function that print the env_data
 * @info_: data informatin constant function prototype.
 * Return: zero
 */
int _myenv(info *info_)
{

	print_list_str(info_->env_data);

	return (0);

}

/**
 * populate_env_list - populates
 * @info_: data type information
 * Return: zero
 */
/*__________________________________________________*/
int populate_env_list(info *info_)
{
	list_t *node = NULL;
	size_t i;


	for (i = 0; environ[i]; i++)
	{
		add_node_end(&node, environ[i], 0);
	}


	info_->env_data = node;
	return (0);
}

