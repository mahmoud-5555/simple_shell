#include "shell.h"

/**
 * is_cmd -_________________
 * @info_: ________________
 * @path_data: ____________________
 *
 * Return: 1 or  0
 */
int is_cmd(info *info_, char *path_data)
{
	struct stat data_st;

	(void)info_;
	if (!path_data || stat(path_data, &data_st))
	{
		return (0);
	}

	if (data_st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - _____________
 * @pathstr: ______________
 * @starter_point: _______________
 * @stop: _________________
 *
 * Return:_______________
 */
char *dup_chars(char *pathstr, int starter_point, int stop)
{
	static char bufffer[1024];
	int i_it = 0, k_it = 0;

	for (k_it = 0, i_it = starter_point; i_it < stop; i_it++)
		if (pathstr[i_it] != ':')
			bufffer[k_it++] = pathstr[i_it];
	bufffer[k_it] = 0;
	return (bufffer);
}

/**
 * find_path - function that use to find the
 *  path_data of the file
 * @info_: data type information
 * @pathstr: the string that we out the path_data from it
 * @cmd_crunt:cmd_crunt
 * Return: string
 */
char *find_path(info *info_, char *pathstr, char *cmd_crunt)
{
	int it_i = 0, curr_pos = 0;
	char *path_data;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd_crunt) > 2) && starts_with(cmd_crunt, "./"))
	{
		if (is_cmd(info_, cmd_crunt))
		{
			return (cmd_crunt);
		}
	}
	while (1)
	{
		if (!pathstr[it_i] || pathstr[it_i] == ':')
		{
			path_data = dup_chars(pathstr, curr_pos, it_i);
			if (!*path_data)
			{
				_strcat_(path_data, cmd_crunt);
			}
			else
			{
				_strcat_(path_data, "/");
				_strcat_(path_data, cmd_crunt);
			}
			if (is_cmd(info_, path_data))
			{
				return (path_data);
			}
			if (!pathstr[it_i])
				break;
			curr_pos = it_i;
		}
		it_i++;
	}
	return (NULL);
}
