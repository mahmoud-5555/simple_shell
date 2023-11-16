#include "shell.h"

/**
 * _mystrcpy - copies a string.
 * @des: the destination.
 * @src: the source.
 *
 * Return: pointer to destination.
 */
char *_mystrcpy(char *des, char *src)
{
	int i = 0;

	if (des == src || src == 0)
		return (des);
	while (src[i])
	{
		des[i] = src[i];
		i++;
	}
	des[i] = 0;
	return (des);
}

/**
 * _mystrdup - duplicates a string.
 * @stn: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_mystrdup(const char *stn)
{
	int length = 0;
	char *ret;

	if (stn == NULL)
		return (NULL);
	while (*stn++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--stn;
	return (ret);
}

/**
 *_prt - prints an input string.
 *@stn: the string to be printed.
 *
 * Return: Nothing.
 */
void _prt(char *stn)
{
	int i = 0;

	if (!stn)
		return;
	while (stn[i] != '\0')
	{
		_putchar(stn[i]);
		i++;
	}
}

/**
 * _myputchar - writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _myputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
