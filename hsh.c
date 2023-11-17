#include "shell.h"

/**
<<<<<<< HEAD
 * hsh - main program
 * @info_: take an information type
 * @vector_args: argument
 *
 * Return: 0 or 1
 */
int hsh(info *info_, char **vector_args)
=======
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
<<<<<<< HEAD
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
=======
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
	}
	return (builtin_ret);
}

<<<<<<< HEAD

=======
/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
<<<<<<< HEAD
void find_cmd(info *info)
{
	char *path_data = NULL;
	int it, k_it;

	info->path_data = info->argvector[0];
=======
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
<<<<<<< HEAD
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
=======
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
			print_error(info, "not found\n");
		}
	}
}

/**
<<<<<<< HEAD
 * fork_cmd - forks functon handle the pid and ppid
 * @info_: the information procciss
 * Return: npthing
 */
void fork_cmd(info *info_)
=======
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
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
<<<<<<< HEAD
		if (execve(info_->path_data, info_->argvector, get_environ(info_)) == -1)
		{
			free_info(info_, 1);
=======
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
<<<<<<< HEAD
		wait(&(info_->status_number));
		if (WIFEXITED(info_->status_number))
		{
			info_->status_number = WEXITSTATUS(info_->status_number);
			if (info_->status_number == 126)
				print_error(info_, "Permission denied\n");
=======
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
		}
	}
}
