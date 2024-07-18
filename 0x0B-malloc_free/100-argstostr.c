#include "main.h"
/**
 * argstostr - function concatenates arguements
 * @ac: number of arguements
 * @av: array of arguements
 *
 * Return: pointer to new string else NULL
*/

char *argstostr(int ac, char **av)
{
	int i; /* iterator to keep track of the length of av */
	int j = 0; /* position on the string */
	int len = 0; /*length of string */
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		len += strlen(av[i]) + 1;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		strcpy(result + j, av[i]); /* copy av to new line */
		j += strlen(av[i]); /* move j to end of av */
		result[j++] = '\n'; /*add newline character */
	}
	return (result);
}
