#include "header.h"

/**
 * _strdup - Function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of a string
 * given as a parameter.
 * @str: string to copy
 * Return: str
 */
char *_strdup(char *str)
{
	char *p = NULL;
	int a;
	int len = 0;

	if (str)
	{
		for (len = 0; *(str + len) != '\0'; len++)
		;
		p = malloc(sizeof(char) * len + 1);
		if (p)
		{
			for (a = 0; a < len || p[a] != '\0'; a++)
			{
				p[a] = str[a];
			}
			p[len] = '\0';
			return (p);
		}
	}
	return (p);
}
/**
 * _strcpy - Function that copies a string.
 * @dest: destiny string
 * @src: source string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	return (dest);
}
/**
 * _strcat - A function that concatenates two strings.
 * @dest: destiny string
 * @src: source string
 * @n: number of bytes of the string
 * Return: (dest)
 */
char *_strcat(char *dest, char *src, int n)
{
	int d, s;

	for (d = 0; dest[d] != '\0'; d++)
		;
	for (s = 0; src[s] != '\0' && s <= n; n--, s++)
	{
		dest[d] = src[s];
		d++;
	}
	return (dest);
}

