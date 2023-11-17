#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
	{
		return (1);
	}
	return (0);
}

/**
<<<<<<< HEAD
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
=======
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
	}
	return (NULL);
}
