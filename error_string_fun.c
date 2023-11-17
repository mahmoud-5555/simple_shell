#include "shell.h"

/**
 *_eputs - print function
 * @string: string that will be printed
 *
 * Return: no return value
 */
void _eputs(char *string)
{
	int itreator = 0;

	if (!string)
		return;
	while (string[itreator] != '\0')
	{
		_eputchar(string[itreator]);
		itreator++;
	}
}



/**
 * _putfd - writ c_char to given file_value
 * @c_char: The char
 * @file_value: The file
 * Return: 1 or -1
 */
int _putfd(char c_char, int file_value)
{
	static int itreator;
	static char buffer[1024];

	if (c_char == -1 || itreator >= 1024)
	{
		write(file_value, buffer, itreator);
		itreator = 0;
	}
	if (c_char != -1)
	{
		buffer[itreator++] = c_char;
	}
	return (1);
}


