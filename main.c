#include "shell.h"

/**
<<<<<<< HEAD
 * main - strting point of the program and the main function
 * @argc: thr numbrer of argumant
 * @argv: the data "argumant"
 *
 * Return: zero or one
 */
int main(int argc, char **argv)
{
	info  info_rmation[] = {0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int filedir = 2;

	asm ("mov %1, %0\n\t"
	"add $3, %0" : "=r" (filedir) : "r" (filedir));

	if (argc == 2)
	{
		filedir = open(argv[1], O_RDONLY);
		if (filedir == -1)
=======
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
<<<<<<< HEAD
				_eputs(argv[0]);

				_eputs(": 0: Can't open ");

				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(-1);
				exit(127);
			}

			return (EXIT_FAILURE);
		}

		info_rmation->readfd = filedir;
	}

	populate_env_list(info_rmation);

	read_history(info_rmation);

	hsh(info_rmation, argv);

=======
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
>>>>>>> 1ba8e5c6279b95a585a16c3670094a502d5dec06
	return (EXIT_SUCCESS);
}
