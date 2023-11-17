#include "shell.h"

/**
 * get_input - __________________
 * @info_:data type information
 *
 * Return: number of bytes
 */
ssize_t get_input(info *info_)
{
	static char *buffer;
	static size_t it, j_it, length;
	ssize_t r = 0;
	char **buf_p = &(info_->argumant), *p;

	_putchar(-1);
	r = input_buf(info_, &buffer, &length);
	if (r == -1)
		return (-1);
	if (length)
	{
		j_it = it;
		p = buffer + it;

		check_chain(info_, buffer, &j_it, it, length);
		while (j_it < length)
		{
			if (is_chain(info_, buffer, &j_it))
				break;
			j_it++;
		}

		it = j_it + 1;
		if (it >= length)
		{
			it = length = 0;
			info_->cmd_buf_type = 0;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buffer;
	return (r);
}
/**
 * read_buf - bufer reader function
 * @info_: data type the information
 * @buffer: buffer
 * @it: size
 *
 * Return: number__
 */
ssize_t read_buf(info *info_, char *buffer, size_t *it)
{
	ssize_t r = 0;

	if (*it)
		return (0);
	r = read(info_->readfd, buffer, 1024);
	if (r >= 0)
		*it = r;
	return (r);
}

/**
 * _getline - the main gri line function
 * @info_: data informtion "data type"
 * @ptr: pinter to string_
 * @length:the lingth of the string
 *
 * Return: number
 */
int _getline(info *info_, char **ptr, size_t *length)
{
	static char buffer[1024];
	static size_t it, l;
	size_t k_byte;
	ssize_t r = 0, s = 0;
	char *st = NULL, *new_p = NULL, *c;

	st = *ptr;
	if (st && length)
		s = *length;
	if (it == l)
		it = l = 0;

	r = read_buf(info_, buffer, &l);
	if (r == -1 || (r == 0 && l == 0))
		return (-1);

	c = _strchr_(buffer + it, '\n');
	k_byte = c ? 1 + (unsigned int)(c - buffer) : l;
	new_p = _realloc(st, s, s ? s + k_byte : k_byte + 1);
	if (!new_p)
		return (st ? free(st), -1 : -1);

	if (s)
		_strncat(new_p, buffer + it, k_byte - it);
	else
		_strncpy(new_p, buffer + it, k_byte - it + 1);

	s += k_byte - it;
	it = k_byte;
	st = new_p;

	if (length)
		*length = s;
	*ptr = st;
	return (s);
}
