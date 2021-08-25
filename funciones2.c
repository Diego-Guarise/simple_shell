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
	int a, b = 0;

	for (a = 0; PATH[a] != NULL; a++)
		;/*Recorre array para reservar memoria*/

	retorno = malloc(sizeof(char *) * a);
	for (a = 0; PATH[a] != NULL; a++)
	{
		algo = wordtoker(inputteclado, " ");
		strcmd = malloc(sizeof(char *) * (strlen(PATH[a])));
		strcmd = string_concat(PATH[a], string_concat("/", algo[b]));
		retorno[a] = malloc(sizeof(char *) * (strlen(strcmd)));
		retorno[a] = _strdup(strcmd);
		printf("%s\n", strcmd);
	}
	return (retorno);
	free(retorno);
}

/**
 * funcionexe - ejecuta el programa (ejemplo: ls, pwd, etc)
 * @retorno: array de string de las posibles direcciones del programa
 * @inputtecladotoker: array de string del input
 * Return: Nothing on Success.
 */

int funcionexe(char **retorno, char **inputtecladotoker)
{
	int a, status;

	pid_t pid = 0;

	if (inputtecladotoker[0] == NULL)
		return (0);
	pid = fork(); /*create child process*/

	if (pid == 0)
	{
		for (a = 0; retorno[a]; a++)
		{
			if (access(retorno[a], X_OK) == 0)
			{
				execve(retorno[a], inputtecladotoker, NULL);
					break;
			}
			if (access(inputtecladotoker[a], X_OK) == 0)
			{
				execve(inputtecladotoker[a], inputtecladotoker, NULL);
					break;
			}
		}
		printf("Command %s cannot be found. RUN!\n", inputtecladotoker[0]);
		exit(98);
	}
		waitpid(-1, &status, 0);
	return (0);
}
