#include "header.h"

/**
 * main - Shell
 * @av: arguments
 * @ac: arguments
 * Return: Nothing on success
 */

int input(char *av, int ac);

int main(void)
{
	char *inputteclado, *path, *exit = "exit", **PATH;
	char **pathyteclado, **inputtecladotoker;
	size_t inputsize = 2048;
	int characters;

	inputteclado = (char *)malloc(sizeof(char) * inputsize);

	path = getenv("PATH");/* Recordar hacer manual esta funcion */
	printf("PATH :%s\n", (path != NULL) ? path : "getenv returned NULL");
	PATH = wordtokerpath(path, ':');
	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		characters = getline(&inputteclado, &inputsize, stdin);
		if (characters == -1)
			return (-1);

		if ((inputteclado[characters - 1]) == '\n')
			inputteclado[characters - 1] = '\0';
		if (strcmp(inputteclado, exit) == 0)
			break;
		printf("Inputteclado es: %s\n", inputteclado);
		pathyteclado = concatpath(inputteclado, PATH);
		inputtecladotoker = wordtoker(inputteclado, " ");
		funcionexe(pathyteclado, inputtecladotoker);
	}
	/**
	 * Liberar espacio de otra funcion en esta?
	 * (wordtoker: Esta funcion nos dio problemas con el valgrind
	 */
	return (0);
}
