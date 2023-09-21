#include "monty.h"
/**
 * _putchar_err - write the character c to stdout
 *
 * @c: The character to print
 * @std:  file descriptors / standard I/O streams
 *
 * Return: 1 : On success .
 *        -1 : is returned, and errno is set appropriately.
 */

int _putchar_err(int std, char c)
{
return (write(std, &c, 1));
}
/**
 * print_number - write an integer number to stdout
 * @std: File descriptor to which the number is printed
 * @n: The number to print
 */
void print_number(int std, int n)
{

	if (n / 10 == 0)
	{
		_putchar_err(std, n + 48);
		return;
	}
	if (n / 10 > 0)
	{
		print_number(std, n / 10);
		_putchar_err(std, (n % 10) + 48);
	}
}

/**
 * _slen - function that calculate lenght of string
 * @s: pointer to string
 * Return: lenght of string
 */
int _slen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _puts - writes the character c to stdout
 * @c: pointer to string
 * Return: number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _puts(char *c)
{
	return (write(1, c, _slen(c)));
}
/**
 * __putchar - write the character c to stdout
 * @c: The character to print
 * Return: 1 : On success .
 *        -1 : is returned, and errno is set appropriately.
 */

int __putchar(char c)
{
	return (write(1, &c, 1));
}


