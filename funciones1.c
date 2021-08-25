#include "header.h"

/**
 * nbr_size - counts length returned
 * @n: int to be printed
 * Return: number of ints printed
 */

int nbr_size(int n)
{
	int counter = 1;

	if (n < 0)
	{
		counter++;
	}
	for(; (n / 10) != 0; counter++)
		n = n / 10;
	return(counter);
}

/**
 * _num_print - prints digits
 * @n: integer to be printed
 *
 * Return: nbr of ints to be printed
 */

int _num_print(int n)
{
	unsigned int nbr;
	nbr = n;

	if ((nbr / 10) != 0)
	{

		_num_print(nbr/10);
	}
	putchar((nbr % 10) + '0');

	return(nbr_size(n));
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
	copy = malloc(sizeof(char *)*a);
	if (!copy)
		return(-1);
	strcpy(copy, buffer);
	string = strtok(copy, " ");
	while (string != NULL)
		{
			b++;
			string = strtok(NULL, " ");
		}
	if (!buffer)
		return(-1);
	free(copy);
	return (b);
}

