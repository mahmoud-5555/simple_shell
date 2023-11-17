#include "shell.h"

/**
 * input_buf - _________________
 * @info_: ___________________
 * @buffer: ___________________
 * @length: ______________________
 * Return: bytes read
 */
ssize_t input_buf(info *info_, char **buffer, size_t *length)
{
	ssize_t r_it_value = 0;
	size_t len_p = 0;

	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigint_Handler);
#if USE_GETLINE
		r_it_value = getline(buffer, &len_p, stdin);
#else
		r_it_value = _getline(info_, buffer, &len_p);
#endif
		if (r_it_value > 0)
		{
			if ((*buffer)[r_it_value - 1] == '\n')
			{
				(*buffer)[r_it_value - 1] = '\0';
				r_it_value--;
			}
			info_->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info_, *buffer, info_->histcount++);
			{
				*length = r_it_value;
				info_->cmd_buf = buffer;
			}
		}
	}
	return (r_it_value);
}


/**
 * sigint_Handler - to handel the contr0l_+C
 * @sig_num: the signal number_ intger value
 *
 * Return: no output th the function
 */
void sigint_Handler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}
