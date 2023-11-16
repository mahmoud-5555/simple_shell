#include "shell.h"

/**
 * _mystrlen - returns the length of a string.
 * @s: string whose length to check.
 *
 * Return: integer length of string
 */
int _mystrlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _mystrcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang.
 * @s2: the second strang.
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _mystrcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * st_with - checks if needle starts with haystack.
 * @srchstack: string to search.
 * @needle: the substring to find.
 *
 * Return: address of next char of haystack or NULL
 */
char *st_with(const char *srchstack, const char *needle)
{
	while (*needle)
		if (*needle++ != *srchstack++)
			return (NULL);
	return ((char *)srchstack);
}

/**
 * _mystrcat - concatenates two strings.
 * @des: destination buffer.
 * @src: source buffer.
 *
 * Return: pointer to destination buffer.
 */
char *_mystrcat(char *des, char *src)
{
	char *ret = des;

	while (*des)
		des++;
	while (*src)
		*des++ = *src++;
	*det = *src;
	return (ret);
}
