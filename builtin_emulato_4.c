#include "shell.h"

/**
 * _mycd - changes the dirrectory
 * @info_: data type information
 *  Return: zero
 */
int _mycd(info *info_)
{
	char *string, *dirrectory, buffer[1024];
	int chdir_ret;

	string = getcwd(buffer, 1024);
	if (!string)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info_->argvector[1])
	{
		dirrectory = _getenv(info_, "HOME=");
		if (!dirrectory)
			chdir_ret = chdir((dirrectory = _getenv(info_, "PWD=")) ? dirrectory : "/");
		else
			chdir_ret = chdir(dirrectory);
	}
	else if (_strcmp(info_->argvector[1], "-") == 0)
	{
		if (!_getenv(info_, "OLDPWD="))
		{
			_puts(string);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info_, "OLDPWD=")), _putchar('\n');
		chdir_ret =
		chdir((dirrectory = _getenv(info_, "OLDPWD=")) ? dirrectory : "/");
	}
	else
		chdir_ret = chdir(info_->argvector[1]);
	if (chdir_ret == -1)
	{
		print_error(info_, "can't cd to ");
		_eputs(info_->argvector[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info_, "OLDPWD", _getenv(info_, "PWD="));
		_setenv(info_, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
