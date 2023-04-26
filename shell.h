#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define MAX_WORD 100
extern char **envt;

#include <fcntl.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


int _atoi(char *s);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t n);
int strcount(char *str, char *delim, int *array);
void free_vector(char **vector, int len);
int exe(char **arg, int n, char **envp);
void _errors(pid_t pid);
bool builtin(char **args, size_t n);
void _exits(char **arg, size_t n);
void zeros(int *array, size_t size);
bool filestats(char *pathname, struct stat *statsbuffer);
bool delimiter(char a, char *delim);
char *str_con(char *s1, char *s2);
char *strs_con(int n, char *s1, char *s2, ...);
char *filepath(char *pathname, struct stat *statsbuffer);
char **tokenization(char *str, char *delim, size_t *counter);
char *_getenv(char *name);
void _printenv(void);
void envi(char **args, size_t n);
#endif
