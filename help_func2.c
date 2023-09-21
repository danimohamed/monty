#include "monty.h"
/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strncmp - This function compares at most the first 'n'
 * characters of the two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of the first characters to compares
 * Return: 0 if the two string are identical or number represent the difference
 * between ASCII value of the two first difference char between to strings
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && n > i; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * *_atoi - convert a string to an integer
 * @argument: pointer to a instruction
 * @stack: pointer to stack list
 * @line_count: number of line in file
 * Return: an integer
 */
int _atoi(char *argument, stack_t *stack, int line_count)
{
	int i = 0, n = 0, neg = 1;

	if (!argument)
	{	fprintf(stderr, "L%d: usage: push integer\n", line_count);
		free(vars.args);
		free_stack(&stack);
		closefile(vars.o_opfile);
		free(vars.line);
		exit(EXIT_FAILURE); }
	if (argument[0] == '-')
	{i++;
		neg = -1; }
	for (; argument[i]; i++)
	{
		if (argument[i] >= '0' && argument[i] <= '9')
			n = n * 10 + (argument[i] - '0');
		else
		{ fprintf(stderr, "L%d: usage: push integer\n", line_count);
			free(vars.args);
			free_stack(&stack);
			closefile(vars.o_opfile);
			free(vars.line);
			exit(EXIT_FAILURE); }
	}
	return (n * neg);
}

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @src: pointer to a string
 * @dest: pointer to a buffer
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *p_dest = NULL;

	p_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p_dest);
}
/**
 * *_strcat -  appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest,
 * and then adds a terminating null byte
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @src: pointer to a string
 * @dest: pointer to a buffer
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *p_dest = dest;
	int l = 0;

	while (*dest != '\0')
	{
		l++;
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p_dest);
}
