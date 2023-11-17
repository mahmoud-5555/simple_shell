#include "shell.h"

/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return:  1,-1,0;
 */
int find_builtin(info *info)
{
	int it, built_in_ret = -1;
	builtin_table builtintbl[] = {{"exit", _myexit}, {"env", _myenv},
		{"help", _myhelp}, {"history", _myhistory}, {"setenv", _mysetenv},
		{"unsetenv", _myunsetenv}, {"cd", _mycd}, {"alias", _myalias},
		{NULL, NULL}
	};

	for (it = 0; builtintbl[it].type; it++)
		if (_strcmp(info->argvector[0], builtintbl[it].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[it].func(info);
			break;
		}
	return (built_in_ret);
}
