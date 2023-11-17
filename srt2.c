#include "shell.h"

/**
 **_strncat - function
 *@dest: the first string
 *@src: the second string
 *@n: the number of bytes
 *Return: the concatenated strring "done"
 */
char *_strncat(char *dest, char *src, int n)
{
	int i_it, j_it;
	char *s = dest;

	i_it = 0;
	j_it = 0;

	while (dest[i_it] != '\0')
	{
		i_it++;
	}
	while (src[j_it] != '\0' && j_it < n)
	{
		dest[i_it] = src[j_it];
		i_it++;
		j_it++;
	}

	if (j_it < n)
	{
		dest[i_it] = '\0';
	}

	return (s);
}

/**
 *_puts - print string
 *@str: the string t
 *
 * Return: No return
 */
void _puts(char *str)
{
	int i_it = 0;

	if (!str)
	{
		return;
	}
	while (str[i_it] != '\0')
	{
		_putchar(str[i_it]);
		i_it++;
	}
}

/**
 * starts_with - checks the @needle in @haystack or not
 * @haystack: search_value
 * @needle: the substring
 *
 * Return: address of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		/*statr search*/
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 **_strncpy - copies a string
 *@dest: the pest word
 *@src: the source  wnna to copy
 *@n: the number of the chats
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i_it, j_it;
	char *s = dest;

	i_it = 0;
	while (src[i_it] != '\0' && i_it < n - 1)
	{
		dest[i_it] = src[i_it];
		i_it++;
	}
	if (i_it < n)
	{
		j_it = i_it;
		while (j_it < n)
		{
			dest[j_it] = '\0';
			j_it++;
		}
	}
	return (s);
}
