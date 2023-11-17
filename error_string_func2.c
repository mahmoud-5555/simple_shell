#include "shell.h"






/**
 * _eputchar - function that print buffers
 * @char_c: key
 * Return: 1.
 */
int _eputchar(char char_c)
{
	static int itreator;
	static char buffer[1024];

	if (char_c == -1 || itreator >= 1024)
	{
		write(2, buffer, itreator);

		itreator = 0;
	}
	if (char_c != -1)
	{
		buffer[itreator++] = char_c;
	}



	return (1);
}

/**
 *_putsfd - _________________
 * @string: _________________________
 * @file_value: ______________________
 *
 * Return: the number of chars that puted
 */
int _putsfd(char *string, int file_value)
{
	int itreator = 0;

	if (!string)
	{
		return (0);
	}
	while (*string)
	{
		itreator += _putfd(*string++, file_value);
	}


	return (itreator);
}
