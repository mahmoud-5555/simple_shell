#include "shell.h"
/**
 * print_d - function prints a decimal number
 * @input: the input
 * @filed: the filedescriptor
 *
 * Return: number of characters
 */
int print_d(int input, int filed)
{
	int (*__putchar)(char) = _putchar;
	int i_it, counter = 0;
	unsigned int abs, current;

	if (filed == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (input < 0)
	{
		abs = -input;
		__putchar('-');
		counter++;
	}
	else
		abs = input;
	current = abs;
	for (i_it = 1000000000; i_it > 1; i_it /= 10)
	{
		if (abs / i_it)
		{
			__putchar('0' + current / i_it);
			counter++;
		}
		current %= i_it;
	}

	__putchar('0' + current);
	counter++;

	return (counter);
}

/**
 *_isalpha - checks for alphabetic character
 *@char_: The character to input
 *Return: 1 if char_ is alphabetic, 0 otherwise
 */
int _isalpha(int char_)
{
	if ((char_ >= 'a' && char_ <= 'z') || (char_ >= 'A' && char_ <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * ffree - frees a an array ogf string that locaut in heap
 * @pointer_to_pointer: string of strings
 */
void ffree(char **pointer_to_pointer)
{
	char **a = pointer_to_pointer;

	if (!pointer_to_pointer)
		return;
	while (*pointer_to_pointer)
		free(*pointer_to_pointer++);
	free(a);
}
/**
 * print_error - prints an error message depand on status
 * @info: information
 * @estr: the spcsfied error
 * Return: 0 or 1
 */
void print_error(info *info, char *estr)
{
	_eputs(info->file_name);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argvector[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * is_delim - functon cop_ two char
 * @c: the char to check
 * @delimlemter: the delimeter string
 * Return: 1 or 0
 */
int is_delim(char c, char *delimlemter)
{
	while (*delimlemter)
		if (*delimlemter++ == c)
		{
			return (1);
		}

	return (0);
}
