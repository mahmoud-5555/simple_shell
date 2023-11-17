#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>
#include <sys/stat.h>



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
/*%%%%%%%% %%%%%%%%*/
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *string;
	struct liststr *next;
} list_t;

/*%%%%%%%%string%%%%%%%%%%*/
/*
int _strlen(char *s);
void _strcpy(char *dest, char *src);
char *_strchr(const char *stetment, char target);
char *_strtok(char *statment, char *delimter);
*/
/*%%%%%%%%execuet%%%%%%%%%%*/
int take_input(void);
int handling_input(char *line, vector *my_vector);
int counter(char *line);
int execu(char *the_file_path, char **the_argum);

/*%%%%%%%% more string %%%%%%%%%%*/

char **strtow__(char *string, char donmanetor);
char *_strchr_(char *string, char char_);
int _putchar(char char_);
char *_strcat_(char *dest, char *src);
char **strtow(char *string, char *donmanetor);
char *_strncat(char *dest, char *src, int n);
void _puts(char *str);
char *starts_with(const char *haystack, const char *needle);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(const char *string);
int _strcmp(char *string1, char *string2);
char *_strcpy(char *dest, char *src);
int _strlen(char *string);

/*%%%%%%%%%%%%%%%% %%%%%%%%%%%%%%%%%*/
/**
 *_the_information_of_the_file_ordered - the data of the command that has bean collected while Running
 *@argumant: line args
 *@line_count: the error count
 *@history: ___hestory "node"
 *@cmd_buf_type: betTwise oprator;
 *@histcount: the histor
 *@file_name: file name
 *@env_changed: ___________
 *@path_data: path
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@readfd: the file dir from which ___
 *@linecount_flag: flag
 *@argvector: vector args
 *@err_num: error "counter"
 *@environ:environ
 *@argcounter: num_of the args
 *@status_number: status_number
 *@env_data:  env list"->->->"
 *@alias: the alias node
 */
typedef struct _the_information_of_the_file_ordered
{
	char *argumant;
	char **argvector;
	/*%%%%%%%%%%%%%*/
	unsigned int line_count;
	int error_number;
	/*%%%%%%%%%%%%%*/
	char *path_data;
	int argcounter;
	/*%%%%%%%%%%%%%%%%*/
	list_t *env_data;
	list_t *alias;
	/*%%%%%%%%%%%%%*/
	char **environ;
	int env_changed;
	/*%%%%%%%%%%%%%*/
	char **cmd_buf;
	int cmd_buf_type;
	/*%%%%%%%%%%%%%*/
	int linecount_flag;
	char *file_name;
	/*%%%%%%%%%%%%%*/
	list_t *history;
	int readfd;
	/*%%%%%%%%%%%%%%%%*/
	int status_number;
	int histcount;
} info;
extern char **environ;

/**
 *struct builtin - ___________________
 *@type:_____
 *@func:_________
 */
typedef struct builtin
{
	char *type;
	int (*func)(info *);
} builtin_table;
#endif
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
void remove_comments(char *string);
int _atoi(char *string);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int bfree(void **ptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
char *convert_number(long int number, int base, int flags);
int print_d(int input, int filed);
int _isalpha(int char_);
void ffree(char **pointer_to_pointer);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
void print_error(info *info, char *estr);
int is_delim(char c, char *delimlemter);
int interactive(info *info);
char *_memset(char *string, char char_b, unsigned int num);
int _erratoi(char *sstring);

/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
list_t *add_node(list_t **head, const char *string, int index);
list_t *add_node_end(list_t **head, const char *string, int index);
size_t print_list_str(const list_t *head);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head);
size_t list_len(const list_t *head);
char **list_to_strings(list_t *head);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
size_t print_list(const list_t *head);
list_t *node_starts_with(list_t *node, char *prefix, char c_char);
ssize_t get_node_index(list_t *head, list_t *node);
void clear_info(info *info__);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
void set_info(info *info__, char **args_vector);
void free_info(info *info__, int all);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int find_builtin(info *info);
void find_cmd(info *info);
void fork_cmd(info *info_);
int hsh(info *info_, char **vector_args);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
ssize_t input_buf(info *info_, char **buffer, size_t *length);
ssize_t get_input(info *info_);
ssize_t read_buf(info *info_, char *buffer, size_t *it);
int _getline(info *info_, char **ptr, size_t *length);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
void sigint_Handler(__attribute__((unused))int sig_num);
char *get_history_file(info *info_);
int write_history(info *info_);
int build_history_list(info *info_, char *buffer, int linecount);
int renumber_history(info *info_);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int is_cmd(info *info_, char *path);
char *dup_chars(char *pathstr, int starter_point, int stop);
char *find_path(info *info_, char *pathstr, char *cmd_crunt);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _eputchar(char char_c);


int _putsfd(char *string, int file_value);
void _eputs(char *string);
int _putfd(char c_char, int file_value);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _myenv(info *info_);
int populate_env_list(info *info_);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _mysetenv(info *info_);
char *_getenv(info *info_, const char *name);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _myunsetenv(info *info_);
int _setenv(info *info_, char *string, char *value);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _unsetenv(info *info_, char *string);
char **get_environ(info *info_);
int _mycd(info *info_);
int _history(info *info_);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int set_alias(info *info_, char *string);
int print_alias(list_t *node);
int _myhelp(info *info_);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _myexit(info *info_);
int unset_alias(info *info_, char *string);

int _alias(info *info_);
int is_chain(info *info_, char *buffer, size_t *pointer_p);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int replace_vars(info *info_);
int is_chain(info *info_, char *buffer, size_t *pointer_p);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
void check_chain(info *info_, char *b, size_t *p_BYTS, size_t i, size_t q);
int replace_string(char **old_string, char *new_string);
int replace_alias(info *info_);
/*%%%%%%%%%%%%%%%% dealing %%%%%%%%%%%%%%%%%*/
int _myhistory(info *info_);
int read_history(info *info_);




int _myalias(info *info_);











