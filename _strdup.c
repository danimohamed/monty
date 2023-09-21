#include "monty.h"

/**
 * *_strdup -  function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * returns a pointer to a new string which is a duplicate of the string str
 * @str: pointer to a string
 * Return: a pointer to duplicated string., or NULL if it fails
 */
char *_strdup(const char *str)
{
int i = 0;
char *pdupstr = NULL;
if (str == NULL)
return (NULL);

while (str[i])
i++;

pdupstr = (char *)malloc((i + 1) * sizeof(char));
if (pdupstr == NULL)
{   _puts_std(2, "Error: malloc failed");
		free(vars.args);
		closefile(vars.o_opfile);
		exit(EXIT_FAILURE); }

for (i = 0; str[i]; i++)
pdupstr[i] = str[i];
pdupstr[i] = '\0';
return (pdupstr);
}
