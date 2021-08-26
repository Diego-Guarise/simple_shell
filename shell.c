#include "header.h"

/**
 * main - Shell
 * Return: Nothing on success
 */

int main(void)
{
	char *inputteclado, *exit = "exit";
	char **inputtecladotoker;
	int characters = 0;
	size_t inputsize;

	/*path = strdup(getenv("PATH"));*/
	/*PATH = wordtokerpath(path, ':');*/
	while (1)
	{
		inputteclado = NULL;
		if (isatty(0))
			write(1, "$ ", 2);
	/*	inputteclado = (char *)malloc(sizeof(char) * inputsize);*/
		characters = getline(&inputteclado, &inputsize, stdin);
		if (characters == -1)
		{
			free(inputteclado);
			break;
		}
		if ((inputteclado[characters - 1]) == '\n')
			inputteclado[characters - 1] = '\0';
		if (strcmp(inputteclado, exit) == 1)
		{
			free(inputteclado);
			break;
		}
		/*pathyteclado = concatpath(inputteclado, PATH);*/
		inputtecladotoker = wordtoker(inputteclado, " ");
		funcionexe(inputtecladotoker);
		/*freearray(pathyteclado);*/
		freearray(inputtecladotoker);
		/*freearray(PATH);*/
		free(inputteclado);
		/*free(path);*/
	}
	/*freearray(PATH);*/
	/*free(inputteclado);*/
	/**
	 * Liberar espacio de otra funcion en esta?
	 * (wordtoker: Esta funcion nos dio problemas con el valgrind
	 */
	return (0);

}
