#include "shell.h"






/**
 * clear_info - delete_ information strucsuer
 * @info__: the class
 */
void clear_info(info *info__)
{
	info__->path_data = NULL;

	info__->argumant = NULL;

	info__->argcounter = 0;

	info__->argvector = NULL;
}






/**
 * free_info - free data in the information data type
 * @info__: opject from the class information
 * @all: bool flags to check if evry think is going will
 */
void free_info(info *info__, int all)
{
	ffree(info__->argvector);
	info__->argvector = NULL;
	info__->path_data = NULL;
	if (all)
	{
		if (!info__->cmd_buf)
		{
			free(info__->argumant);
		}
		if (info__->env_data)
		{
			free_list(&(info__->env_data));
		}
		if (info__->history)
		{
			free_list(&(info__->history));
		}
		if (info__->alias)
		{
			free_list(&(info__->alias));
		}
		ffree(info__->environ);
			info__->environ = NULL;
		bfree((void **)info__->cmd_buf);
		if (info__->readfd > 2)
			close(info__->readfd);
		_putchar(-1);
	}
}

