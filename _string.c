#include "main.h"

/**
* _strlen - function to count the legnth of the string
* @s: the input that we deal with it
* Return:  (Success)
*/
int _strlen(char *s)
{
	int it = 0;

	int counter = 0;

	while (*(s + it) != '\0')
	{
		counter++;
		it++;
	}
	return (counter);
}

/**
* _strcpy - a function that copies the string pointed to by src
* @dest: input og the function (to)
* @src: the input of the function (from)
* Return: string
*/
void _strcpy(char *dest, char *src)
{
	int it = 0;

	int it2 = 0;

	while (*(src + it) != '\0')
	{
		it++;
	}

	for ( ; it2 < it ; it2++)
		dest[it2] = src[it2];

	dest[it] = '\0';
}

/**
* _strchr - a function that search of char "target"
* @stetment: the string what we search on it
* @target: the target
* Return: string
*/
char *_strchr(const char *stetment, char target)
{
	while (*stetment != '\0')
	{
		if (*stetment == target)
		{
			return ((char *)stetment);
		}
		stetment++;
	}
	return (NULL);
}

/**
* counter - function that count the order to make an array with spcfic size
* @line: the string that will be cuted
* Return: number of becis;
*/
int counter(char *line)
{
	int n = 0;

	char *ordar;

	ordar = strtok(line, " ");
	while (ordar)
	{
		if (*ordar != 10)
			n++;
		ordar = strtok(NULL, " ");
	}
	return (n);
}


