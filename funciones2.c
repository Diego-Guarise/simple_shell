#include "header.h"

/**
 * concatpath - concatena inputteclado con PATH
 * Descripcion - concatena el primer argumento del input con la array de
 * string en la que se encuentra las direcciones de PATH,
 * cada combinacion posible de la posible ubicacion de un programa
 * @inputteclado: la entrada por teclado
 * @PATH: array de string que contiene a PATH
 * Return: inputteclado y PATH concatenado
*/

char **concatpath(char *inputteclado, char **PATH)
{
	char *strcmd, **algo, **retorno;
	int a, b = 0, c;

	for (a = 0; PATH[a] != NULL; a++)
		;/*Recorre array para reservar memoria*/
	retorno = malloc(sizeof(char *) * a);
	for (c = 0; c != (a - 1); c++)
	{
		algo = wordtoker(inputteclado, " ");
		strcmd = malloc(sizeof(char *) * (strlen(PATH[c])));
		strcmd = string_concat(PATH[c], string_concat("/", algo[b]));
		retorno[c] = malloc(sizeof(char *) * (strlen(strcmd)));
		retorno[c] = _strdup(strcmd);
	}
	return (retorno);
	free(retorno);
}

/**
 * funcionexe - ejecuta el programa (ejemplo: ls, pwd, etc)
 * @inputtecladotoker: array de string del input
 * Return: Nothing on Success.
 */

int funcionexe(char **inputtecladotoker)
{
	int status;

	pid_t pid = 0;

	if (inputtecladotoker[0] == NULL)
		return (0);
	pid = fork(); /*create child process*/

	if (pid == 0)
	{
		if (access(inputtecladotoker[0], X_OK) == 0)
		{
			execve(inputtecladotoker[0], inputtecladotoker, NULL);
		}
		printf("Command %s cannot be found. RUN!\n", inputtecladotoker[0]);
		exit(98);
	}
		waitpid(-1, &status, 0);
	return (0);
}
