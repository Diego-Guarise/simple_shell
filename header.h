#ifndef HEADER_H
#define HEADER_H
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Funtions prototypes */
int tokerpath(char *buffer);
int toker(char *buffer);
char **wordtoker(char *buffer, char *separator);
char **wordtokerpath(char *buffer, char separator);
char *_strcat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *getPath();
char *string_concat(char *s1, char *s2);
char *pathtoker(int argc, char *argv[]);
char **concatpath(char *inputteclado, char **PATH);
int funcionexe(char **retorno, char **inputtecladotoker);
void freearray(char **array);
#endif
