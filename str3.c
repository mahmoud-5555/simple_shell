#include "shell.h"
/**
 * _strdup - duplicates a string and return new one in same var no heap locate
 * @string: the string what wnna to dublecate
 *
 * Return: new string whitch is the duplicated string
 */
char *_strdup(const char *string)
{

	int len = 0;
	char *ptr;

	if (string == NULL)
	{
		return (NULL);
	}

	while (*string++)
	{
		len++;
	}

	ptr = malloc(sizeof(char) * (len + 1));

	if (!ptr)
	{
		return (NULL);
	}

	for (len++; len--;)
	{
		ptr[len] = *--string;
	}

	return (ptr);
}

/**
 * _strcmp - function that compere between the string
 * @string1: the first strang
 * @string2: the second strang
 * Return: comparing value
 */
int _strcmp(char *string1, char *string2)
{

	while (*string1 && *string2)
	{
		if (*string1 != *string2)
		{
			return (*string1 - *string2);
		}

		string1++;
		string2++;
	}


	if (*string1 == *string2)
	{
		return (0);
	}
	else
	{
		return (*string1 < *string2 ? -1 : 1);
	}
}

/**
 * _strcpy - copies a string
 * @dest: to
 * @src: from
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int _it = 0;


	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[_it])
	{
		dest[_it] = src[_it];
		_it++;
	}
	dest[_it] = 0;
	{
		return (dest);
	}
}

/**
 * _strlen - returns the len of a string
 * @string: the string
 *
 * Return: integer value
 */
int _strlen(char *string)
{
	int i_it = 0;



	if (!string)
	{
		return (0);
	}

	while (*string++)
	{
		i_it++;
	}
	return (i_it);
}

