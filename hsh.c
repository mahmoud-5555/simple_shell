#include "shell.h"

/**
 * hsh - main program
 * @info_: take an information type
 * @vector_args: argument
 *
 * Return: 0 or 1
 */
int hsh(info *info_, char **vector_args)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info_);
		if (interactive(info_))
			_puts("$ ");
		_eputchar(-1);
		r = get_input(info_);
		if (r != -1)
		{
			set_info(info_, vector_args);
			builtin_ret = find_builtin(info_);
			if (builtin_ret == -1)
			{
				find_cmd(info_);
			}
		}
		else if (interactive(info_))
		{
			_putchar('\n');
		}
		free_info(info_, 0);
	}
	write_history(info_);
	free_info(info_, 1);
	if (!interactive(info_) && info_->status_number)
	{
		exit(info_->status_number);
	}
	if (builtin_ret == -2)
	{
		if (info_->error_number == -1)
			exit(info_->status_number);
		exit(info_->error_number);
	}
	return (builtin_ret);
}



/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info *info)
{
	char *path_data = NULL;
	int it, k_it;

	info->path_data = info->argvector[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (it = 0, k_it = 0; info->argumant[it]; it++)
		if (!is_delim(info->argumant[it], " \t\n"))
			k_it++;
	if (!k_it)
		return;

	path_data = find_path(info, _getenv(info, "PATH="), info->argvector[0]);
	if (path_data)
	{
		info->path_data = path_data;
		fork_cmd(info);
	}

	else
	{	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argvector[0][0] == '/') && is_cmd(info, info->argvector[0]))
			fork_cmd(info);

		else if (*(info->argumant) != '\n')
		{
			info->status_number = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks functon handle the pid and ppid
 * @info_: the information procciss
 * Return: npthing
 */
void fork_cmd(info *info_)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info_->path_data, info_->argvector, get_environ(info_)) == -1)
		{
			free_info(info_, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info_->status_number));
		if (WIFEXITED(info_->status_number))
		{
			info_->status_number = WEXITSTATUS(info_->status_number);
			if (info_->status_number == 126)
				print_error(info_, "Permission denied\n");
		}
	}
}
