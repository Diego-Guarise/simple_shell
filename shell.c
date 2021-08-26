#include "header.h"

/**
 * main - Shell
 * Return: Nothing on success
 */

int main(void)
{
	char *inputteclado, *path, *exit = "exit", **PATH;
	char **pathyteclado, **inputtecladotoker;
	size_t inputsize = 2048;
	int characters;

	path = strdup(getenv("PATH"));
	PATH = wordtokerpath(path, ':');
	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		inputteclado = (char *)malloc(sizeof(char) * inputsize);
		characters = getline(&inputteclado, &inputsize, stdin);
		if (characters == -1)
		{
			free(inputteclado);
			break;
		}
		if ((inputteclado[characters - 1]) == '\n')
			inputteclado[characters - 1] = '\0';
		if (strcmp(inputteclado, exit) == 1)
			break;
		pathyteclado = concatpath(inputteclado, PATH);
		inputtecladotoker = wordtoker(inputteclado, " ");
		funcionexe(pathyteclado, inputtecladotoker);
		freearray(pathyteclado);
		freearray(inputtecladotoker);
		/*freearray(PATH);*/
		free(inputteclado);
		/*free(path);*/
	}
	freearray(PATH);

	/**
	 * Liberar espacio de otra funcion en esta?
	 * (wordtoker: Esta funcion nos dio problemas con el valgrind
	 */
	return (0);
}
