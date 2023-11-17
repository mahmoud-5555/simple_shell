#include "shell.h"

/**
 * _myexit - the function dont make any think just close the program
 * @info_: data type informatin
 *  Return: exits
 */
int _myexit(info *info_)
{
	int exit_flag;

	if (info_->argvector[1])
	{
		exit_flag = _erratoi(info_->argvector[1]);

		if (exit_flag == -1)
		{
			info_->status_number = 2;
			print_error(info_, "Illegal number: ");
			_eputs(info_->argvector[1]);
			_eputchar('\n');
			return (1);
		}
		info_->error_number = _erratoi(info_->argvector[1]);
		return (-2);

	}
	info_->error_number = -1;
	return (-2);
}

/**
 * _myhelp - printer of the helper data
 * @info_: dtat type information
 *  Return: zero
 */
int _myhelp(info *info_)
{
	char **arg_array;

	arg_array = info_->argvector;
	_puts("help call works. Function not yet implemented \n");
	if (0)
	{
		_puts(*arg_array);
	}
	return (0);
}
