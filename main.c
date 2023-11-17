#include "shell.h"

/**
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
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
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

	return (EXIT_SUCCESS);
}
