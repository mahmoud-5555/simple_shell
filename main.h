#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*%%%%%%%%vector%%%%%%%%%%%%*/
/**
 * struct vector - is an dainamic array of string
 * @ordar_splits: are the data of the vector
 * @size:number of element that the vector have it
 * @capacity: the large number of the element can the vector stor
 * it in the caurnt located
*/
typedef struct vector
{
	char **ordar_splits;
	int size;
	int capacity;
} vector;

int vector_push(vector *my_vector, char *data);
int vector_free(vector *my_vector);

/*%%%%%%%%string%%%%%%%%%%*/
int _strlen(char *s);
void _strcpy(char *dest, char *src);
char *_strchr(const char *stetment, char target);
char *_strtok(char *statment, char *delimter);

/*%%%%%%%%execuet%%%%%%%%%%*/
int take_input(void);
int handling_input(char *line, vector *my_vector);
int counter(char *line);
int execu(char *the_file_path, char **the_argum);
//erorr_exceute
//path_checker
//get_path
//file :: will be read from main_args
//getline
//build_in_function_checker
//


#endif
