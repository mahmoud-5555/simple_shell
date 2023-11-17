#include "shell.h"
/**
 * **strtow__ - split the string
 * @string: the input string
 * @donmanetor: the delimeter
 * Return: p_pointer
 */
char **strtow__(char *string, char donmanetor)
{
	int i_it, j_it, k_it, m_it, num_of_words = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (i_it = 0; string[i_it] != '\0'; i_it++)
		if ((string[i_it] != donmanetor && string[i_it + 1] == donmanetor) ||
		    (string[i_it] != donmanetor && !string[i_it + 1]) ||
			string[i_it + 1] == donmanetor)
			num_of_words++;
	if (num_of_words == 0)
		return (NULL);
	s = malloc((1 + num_of_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i_it = 0, j_it = 0; j_it < num_of_words; j_it++)
	{
		while (string[i_it] == donmanetor && string[i_it] != donmanetor)
			i_it++;
		k_it = 0;
		while (string[i_it + k_it] != donmanetor && string[i_it + k_it]
		&& string[i_it + k_it] != donmanetor)
			k_it++;
		s[j_it] = malloc((k_it + 1) * sizeof(char));
		if (!s[j_it])
		{
			for (k_it = 0; k_it < j_it; k_it++)
				free(s[k_it]);
			free(s);
			return (NULL);
		}
		for (m_it = 0; m_it < k_it; m_it++)
		{
			s[j_it][m_it] = string[i_it++];
		}
		s[j_it][m_it] = 0;
	}
	s[j_it] = NULL;
	return (s);
}

/**
 **_strchr_ - locates a character in side the  string___
 *@string: the string what we wnna to searchto  the char in side it
 *@char_: the "char"
 *Return: (s) a pointer to the memory area s
 */
char *_strchr_(char *string, char char_)
{
	/* Loop through each character in the string*/
	do {
		/* Check if the current character matches the input character*/
		if (*string == char_)
		{
			return (string);
		}
	} while (*string++ != '\0');

	return (NULL);
}

/**
 * _putchar - function that use the write function
 * to print one char
 * @char_: The character to print
 *
 * Return: On success 1 or -1 to failue
 */
int _putchar(char char_)
{
	static int i_it;
	static char buffer[1024];

	if (char_ == -1 || i_it >= 1024)
	{
		write(1, buffer, i_it);
		i_it = 0;
	}


	if (char_ != -1)
	{
		buffer[i_it++] = char_;
	}
	return (1);
}

/**
 * _strcat_ - concatenates the string
 * @dest: the first string
 * @src: the source
 *
 * Return: new string
 */
char *_strcat_(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;


	return (ret);
}

/**
 * **strtow - splits with ignoring
 * @string: the input string
 * @donmanetor: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *string, char *donmanetor)
{
	int i_it, _it, k_it, m_it, numwords = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!donmanetor)
		donmanetor = " ";
	for (i_it = 0; string[i_it] != '\0'; i_it++)
		if (!is_delim(string[i_it], donmanetor) &&
		(is_delim(string[i_it + 1], donmanetor) || !string[i_it + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i_it = 0, _it = 0; _it < numwords; _it++)
	{
		while (is_delim(string[i_it], donmanetor))
			i_it++;
		k_it = 0;
		while (!is_delim(string[i_it + k_it], donmanetor) && string[i_it + k_it])
			k_it++;
		s[_it] = malloc((k_it + 1) * sizeof(char));
		if (!s[_it])
		{
			for (k_it = 0; k_it < _it; k_it++)
				free(s[k_it]);
			free(s);
			return (NULL);
		}
		for (m_it = 0; m_it < k_it; m_it++)
			s[_it][m_it] = string[i_it++];
		s[_it][m_it] = 0;
	}
	s[_it] = NULL;
	return (s);
}

