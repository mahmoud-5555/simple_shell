#include "main.h"

/**
 * vector_free - function that free the data in side the vector and convert all
 * opject_eldement'sruct vector to defult'
 * @my_vector: pass py refrance to the vector
 * Return: 0
*/
int vector_free(vector *my_vector)
{
	if (my_vector->ordar_splits != NULL)
	{
		free(my_vector->ordar_splits);
		my_vector->capacity = 0;
		my_vector->size = 0;
		my_vector->ordar_splits = NULL;
		return (0);
	}
	return (0);
}

/**
 * vector_push - function that push new element to the vector
 *
 * @my_vector: pass py refrance to the vector
 * @data: the data the you wanna to push
 * Return: 0
*/
int vector_push(vector *my_vector, char *data)
{
	(my_vector->size) += 1;
	if ((my_vector->ordar_splits) == NULL)
	{
		my_vector->ordar_splits = malloc(sizeof(char *) * my_vector->capacity);
		if ((my_vector->ordar_splits) == NULL)
			return (-1);
	}

	else
	{
		if (my_vector->capacity <= my_vector->size)
		{
			my_vector->capacity *= 2;
			char **new_splits = realloc(my_vector->ordar_splits,
				(my_vector->capacity) * sizeof(char *));
			if (new_splits == NULL)
				return (-1);
			my_vector->ordar_splits = new_splits;
		}
	}
	(my_vector->ordar_splits)[(my_vector->size) - 1] = data;
	return (0);
}
