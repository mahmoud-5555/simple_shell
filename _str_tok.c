#include"main.h"

/**
 * _is_delim - function that compare_ and search of the string
 * @c: the char what be compare it
 * @delimter: seached opject
 * Return: 0 or 1
*/
unsigned int _is_delim(char c, char *delimter)
{
	while (*delimter != '\0')
	{
		if (c == *delimter)
			return (1);
		delimter++;
	}
	return (0);
}

/**
* _strtok - a function that cut string by delimiters
* @statment: the statment thar will be cuted
* @delimter: the target "startand the end"
* Return: string
*/
char *_strtok(char *statment, char *delimter)
{
	static char *backup_string;/*static varible to save last pointer*/

	char *ret = NULL;

	if (!statment)
		statment = backup_string;

	if (!statment)
		return (NULL);

	while (1)
	{
		if (_is_delim(*statment, delimter))
		{
			statment++;
			continue;
		}
		if (*statment == '\0')
			return (NULL);
		break;
	}
	ret = statment;

	while (1)
	{
		if (*statment == '\0')
		{
			backup_string = statment;
			return (ret);
		}
		if (_is_delim(*statment, delimter))
		{
			*statment = '\0';
			backup_string = statment + 1;
			return (ret);
		}
		statment++;
	}
}
