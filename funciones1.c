#include "header.h"

/**
 * freearray - libera array de strings
 * @array: array de string
 */
void freearray(char **array)
{
	int a = 0;

	for (; array[a] != NULL; a++)
		free(array[a]);
	free(array);
}

/**
 * toker - Function to copy buffer
 * @buffer: Command line
 * Description: recibe una string y la tokeniza y devuelve el numero de tokens
 * Return: Amount of tokens
 */

int toker(char *buffer)
{
	char *string, *copy;
	int a, b = 0;

	for (a = 0; buffer[a] != '\0'; a++)
		;
	copy = malloc(sizeof(char *) * a);
	if (!copy)
		return (-1);
	strcpy(copy, buffer);
	string = strtok(copy, " ");
	while (string != NULL)
	{
		b++;
		string = strtok(NULL, " ");
	}
	free(copy);
	return (b);
}

