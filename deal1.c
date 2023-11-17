#include "shell.h"
/**
 * remove_comments - handler of ->"#" with -> "\0"
 * @string: place which modephide
 *
 * Return: Always 0;
 */
void remove_comments(char *string)
{
	int i_it;

	for (i_it = 0; string[i_it] != '\0'; i_it++)
		if (string[i_it] == '#' && (!i_it || string[i_it - 1] == ' '))
		{
			string[i_it] = '\0';
			break;
		}
}
/**
 *_atoi - ""converts"" string to number -> intger
 *@string: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *string)
{
	int i_it, sign = 1, fl = 0, out;
	unsigned int result = 0;

	for (i_it = 0;  string[i_it] != '\0' && fl != 2; i_it++)
	{
		if (string[i_it] == '-')
			sign *= -1;

		if (string[i_it] >= '0' && string[i_it] <= '9')
		{
			fl = 1;
			result *= 10;
			result += (string[i_it] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}
	/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
	if (sign == -1)
		out = -result;
	else
		out = result;

	return (out);
}

/**
 * bfree - free buffers and pointer
 * @ptr: the place of"wnna freeing"
 *
 * Return: one or zero.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}

/**
 * _realloc - realloc
 * @ptr: the pointer pointer
 * @old_size: old_size
 * @new_size: ew_size
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pointer;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
	pointer = malloc(new_size);
	if (!pointer)
	{
		return (NULL);
	}
	/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		pointer[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (pointer);
}

/**
 * convert_number - CON_FUNC
 * @number: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int number, int base, int flags)
{
	static char *array;
	static char buf[50];
	char sign = 0;
	char *ptr;
	unsigned long n = number;
	/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
	if (!(flags & 2) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{

		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}
