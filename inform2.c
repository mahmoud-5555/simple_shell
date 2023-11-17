#include "shell.h"

/**
 * set_info - put value information in "information data type"
 * @info__: opject from the class
 * @args_vector: argument vector
 */
void set_info(info *info__, char **args_vector)
{
	int i_it = 0;

	info__->file_name = args_vector[0];
	if (info__->argumant)
	{
		info__->argvector = strtow(info__->argumant, " \t");
		if (!info__->argvector)
		{

			info__->argvector = malloc(sizeof(char *) * 2);
			if (info__->argvector)
			{
				info__->argvector[0] = _strdup(info__->argumant);
				info__->argvector[1] = NULL;
			}
		}
		for (i_it = 0; info__->argvector && info__->argvector[i_it]; i_it++)
			;
		info__->argcounter = i_it;

		replace_alias(info__);
		replace_vars(info__);
	}
}
