#include "header.h"
/**
 *  - Function to copy buffer
 * @buffer: Command line
 * Description: recibe una string y la tokeniza y devuelve la palabra
 * Return: Amount of tokens
 */

char **wordtoker(char *buffer, char *separator)
{
	char *copybuffer, *string2, **algo, *tmp = " ";
	int a, a2, b;
	
	copybuffer = _strdup(buffer);
	b = toker(copybuffer);
	algo = malloc(sizeof(char*) * (b + 1));
	if (!algo)
		return(NULL);
	algo[b] = NULL;
	tmp = separator;
	string2 = strtok(copybuffer, tmp);
	for (a2 = 0; a2 < b; a2++)
	{
		algo[a2] = _strdup(string2);
		if (!algo[a2])
			return(NULL);
		string2 = strtok(NULL, tmp);
	}

	for (a = 0; algo[a] != NULL; a++)
	;
	return(algo);	
	/*libera memoria en shell, pero sigue dando mal*/
}

char **wordtokerpath(char *buffer, char separator)
{
	char *string2, **algo, tmp[] = ":";
	int a2, length, b;

	b = tokerpath(buffer);
	algo = malloc(sizeof(char*) * (b + 1));
	if (!algo)
		return(NULL);
	algo[b] = NULL;
	tmp[0] = separator;
	string2 = strtok(buffer, tmp);
	for (a2 = 0; a2 < b; a2++)
	{
		length = strlen(string2);
		algo[a2] = malloc(length);
		if (!algo[a2])
			return(NULL);
		algo[a2] = _strdup(string2);
		string2 = strtok(NULL, tmp);
	}

	return (algo);
	
	/*libera memoria en shell, pero sigue dando mal*/
}

/**
 * toker - Function to copy buffer
 * @buffer: Command line
 * Description: recibe una string y la tokeniza y devuelve el numero de tokens
 * Return: Amount of tokens
 */

int tokerpath(char *buffer)
{
	char *string, *copy;
	int a, b = 0;
	
	for (a = 0; buffer[a] != '\0'; a++)
		;
	copy = malloc(sizeof(char *)*a);
	if (!copy)
		return(-1);
	strcpy(copy, buffer);
	string = strtok(copy, ":");
	while (string != NULL)
		{
			b++;
			string = strtok(NULL, ":");
		}
	if (!buffer)
		return(-1);
return (b);
}

/**
 * string_nconcat -  Function that concatenates two strings.
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
