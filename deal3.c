#include "shell.h"
/**
 * interactive -  true in interactive_mode to ditearmin whitch type of out
 * @info: data type "information"
 * Return: one or zero
 */
int interactive(info *info)
{

	return (isatty(STDIN_FILENO) && info->readfd <= 2);

}

/**
 **_memset - put conist value in the space
 *@string: the pointer to the memory area
 *@char_b: the byte to fill *string with
 *@num: the amount of bytes to be filled
 *Return: (string) a pointer to the memory area string
 */
char *_memset(char *string, char char_b, unsigned int num)
{
	unsigned int itretor;

	for (itretor = 0; itretor < num; itretor++)
	{
		string[itretor] = char_b;
	}
	return (string);
}

/**
 * _erratoi - converts a string to an integer
 * @sstring: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *sstring)
{
	int itretor = 0;
	unsigned long int result = 0;

	if (*sstring == '+')
	{
		sstring++;  /* TODO: why does this make main return 255? */
	}
	for (itretor = 0;  sstring[itretor] != '\0'; itretor++)
	{
		if (sstring[itretor] >= '0' && sstring[itretor] <= '9')
		{
			result *= 10;
			result += (sstring[itretor] - '0');
			if (result > INT_MAX)
			{
				return (-1);
			}
		}
		else
			return (-1);
	}
	return (result);
}
