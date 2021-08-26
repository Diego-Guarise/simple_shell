#include "header.h"
/**
 * wordtoker - Function to copy buffer
 * @buffer: Command line
 * @separator: Separator character
 * Description: recibe una string y la tokeniza y devuelve la palabra
 * Return: Amount of tokens
 */

char **wordtoker(char *inputteclado, char *separator)
{
	char *copyinputteclado, *string2, **inputtecladotoker, *tmp = " ";
	int a2, b;

	copyinputteclado = _strdup(inputteclado);
	b = toker(copyinputteclado);
	inputtecladotoker = malloc(sizeof(char *) * (b + 1));
	if (!inputtecladotoker)
		return (NULL);
	inputtecladotoker[b] = NULL;
	tmp = separator;
	string2 = strtok(copyinputteclado, tmp);
	for (a2 = 0; a2 < b; a2++)
	{
		inputtecladotoker[a2] = _strdup(string2);
		if (!inputtecladotoker[a2])
			return (NULL);
		string2 = strtok(NULL, tmp);
	}
	return (inputtecladotoker);
	/*libera memoria en shell, pero sigue dando mal*/
}

/**
 * wordtokerpath - Function to copy path
 * @buffer: Command line
 * @separator: Separator character
 * Return: Ponter to 2D Array
 */

char **wordtokerpath(char *path, char separator)
{
	char *string2, **arraypath, tmp[] = ":", *copypath;
	int a2, length, b;

	b = tokerpath(path);
	arraypath = malloc(sizeof(char *) * (b + 2));
	if (!arraypath)
		return (NULL);
	copypath = _strdup(path);
	toker(copypath);/*Revisar memoria al mover el puntero*/
	arraypath[b] = _strdup(copypath);
	arraypath[b + 1] = NULL;
	tmp[0] = separator;
	string2 = strtok(path, tmp);
	for (a2 = 0; a2 < b; a2++)
	{
		length = strlen(string2);
		arraypath[a2] = malloc(length);
		if (!arraypath[a2])
			/*free(arraypath[a2])*/
			return (NULL);
		arraypath[a2] = _strdup(string2);
		string2 = strtok(NULL, tmp);
	}
	
	return (arraypath);

	/*libera memoria en shell, pero sigue dando mal*/
}

/**
 * tokerpath - Function to copy buffer
 * @path: Command line
 * Description: recibe una string y la tokeniza y devuelve el numero de tokens
 * Return: Amount of tokens
 */

int tokerpath(char *path)
{
	char *string, *copy;
	int b = 0;

	copy = _strdup(path);/*copy path into copy*/
	string = _strdup(strtok(copy, ":"));
	while (string != NULL)
	{
		b++;
		free(string);
		string = _strdup(strtok(NULL, ":"));
	}
	free(string);
	free(copy);
return (b);
}

/**
 * string_concat -  Function that concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to a newly allocated space in memory
 */
char *string_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int a = 0, b = 0, c = 0, d = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (a = 0; s1[a] != '\0'; a++)
		;
	for (b = 0; s2[b] != '\0'; b++)
		;
	s3 = malloc(sizeof(char) * (a + b + 1));
	if (s3 == NULL)
		return (NULL);
	for (c = 0; c < a ; c++)
		s3[c] = s1[c];
	for (d = 0; d < b; d++)
		s3[c + d] = s2[d];
	s3[c + d]  = '\0';
	return (s3);
	free(s3);
}
