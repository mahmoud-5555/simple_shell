#include "shell.h"

/**
 * get_history_file - get_history_file
 * @info_: information data type
 * Return: string the history
 */

char *get_history_file(info *info_)
{
	char *buffer, *directory;

	directory = _getenv(info_, "HOME=");
	if (!directory)
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (_strlen(directory) +
	_strlen(".simple_shell_history") + 2));
	if (!buffer)
	{
		return (NULL);
	}
	buffer[0] = 0;

	_strcpy(buffer, directory);

	_strcat_(buffer, "/");

	_strcat_(buffer, ".simple_shell_history");

	return (buffer);
}

/**
 * write_history -  write the hestory
 * @info_: the informatin data type
 * Return: 1 or -1__
 */
int write_history(info *info_)
{
	ssize_t file_value;
	char *filename = get_history_file(info_);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	file_value = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);

	free(filename);
	if (file_value == -1)
	{
		return (-1);
	}
	for (node = info_->history; node; node = node->next)
	{
		_putsfd(node->string, file_value);
		_putfd('\n', file_value);
	}
	_putfd(-1, file_value);
	close(file_value);
	return (1);
}

/**
 * read_history - read_history
 * @info_: _______________________
 * Return: 0
 */
int read_history(info *info_)
{
	int it, last_node = 0, linecount = 0;
	ssize_t file_value, rdlen, file_size = 0;
	struct stat st;
	char *buffer = NULL, *filename = get_history_file(info_);

	if (!filename)
		return (0);

	file_value = open(filename, O_RDONLY);
	free(filename);
	if (file_value == -1)
		return (0);
	if (!fstat(file_value, &st))
		file_size = st.st_size;
	if (file_size < 2)
		return (0);
	buffer = malloc(sizeof(char) * (file_size + 1));
	if (!buffer)
		return (0);
	rdlen = read(file_value, buffer, file_size);
	buffer[file_size] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(file_value);
	for (it = 0; it < file_size; it++)
		if (buffer[it] == '\n')
		{
			buffer[it] = 0;
			build_history_list(info_, buffer + last_node, linecount++);
			last_node = it + 1;
		}
	if (last_node != it)
		build_history_list(info_, buffer + last_node, linecount++);
	free(buffer);
	info_->histcount = linecount;
	while (info_->histcount-- >= 4096)
		delete_node_at_index(&(info_->history), 0);
	renumber_history(info_);
	return (info_->histcount);
}

/**
 * build_history_list - push history to the hstory data
 * @info_: information data type
 * @buffer: buffer
 * @linecount: linecount
 *
 * Return: Always 0
 */
int build_history_list(info *info_, char *buffer, int linecount)
{
	list_t *node = NULL;

	if (info_->history)
		node = info_->history;
	add_node_end(&node, buffer, linecount);

	if (!info_->history)
		info_->history = node;
	return (0);
}

/**
 * renumber_history - out put the number of the hestory
 * @info_: the information data_type
 *
 * Return: the new histcount
 */
int renumber_history(info *info_)
{
	list_t *node = info_->history;
	int it = 0;

	while (node)
	{
		node->num = it++;
		node = node->next;
	}
	return (info_->histcount = it);
}
