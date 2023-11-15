#include "main.h"

/**
 * main - the main process of the program well be in <main()>
 * @argc:_________
 * @argv:_________
 * Return:________
*/
int main(int argc, char *argv[])
{
	int ex = 0;
	(void)argc;
	(void)argv;
	while (1)
	{
		write(1, "$ ", 2);
		ex = take_input();
		if (ex)
			return (0);
	}


	return (0); /*every think going well*/
}

/**
 * take_input - print the '$' signand after that  take an input fro the user
 *
 * Return: if the user tring git out from the shell will return -1 eles 0
 *
*/
int take_input(void)
{
	char *line = NULL;
	size_t n;
	ssize_t out;
	vector my_vector = {NULL, 0, 5};

	out = getline(&line, &n, stdin);
	if (out == -1)
	{
		vector_free(&my_vector);
		write(1, "\n", 1);
		free(line);
		return (1);
	}
	handling_input(line, &my_vector);
	vector_free(&my_vector);
	free(line);
	return (0);
}

int handling_input(char *line, vector *my_vector)
{
	int counter = 0, i = 0;
	char *first_order = NULL;
	char *ordar;
	char **args = NULL;

	ordar = _strtok(line, " ");
	while (ordar)
	{
		if (*ordar != 10 && counter != 0)
			vector_push(my_vector, ordar);
		else if (*ordar != 10 && counter == 0)
			first_order = ordar;
		else if (*ordar != 10 && counter == 0 && first_order == NULL)
			first_order = ordar;
		ordar = _strtok(NULL, " ");
		counter++;
	}
	if (my_vector->ordar_splits != NULL)
		args = malloc(sizeof(char *) * (my_vector->size));
	for (; i < my_vector->size; i++)
	{
		args[i] = (my_vector->ordar_splits)[i];
	};
	execu(first_order, args);
	free(args);
	return (0);
}

int execu(char *the_file_path, char **the_argum)
{
	// if(file_is_exist())/*check if the file is exsist*/
	// {
	
	// }
	execve(the_file_path, the_argum, NULL);
	return (0);
}
