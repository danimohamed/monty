#include "monty.h"

/**
 * _puts_std - writes the string to the specific std.
 * @str: pointer to string
 * @std: file descriptors / standard I/O streams
 * Return: number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _puts_std(int std, char *str)
{
	return (write(std, str, _slen(str)));
}


/**
 * print_error - Print an error message.
 * @err_msg: Error message to be displayed
 * @line_number: a count associated with the current instruction line
 * @opcode: instruction of monty code
 */
void print_error(int line_number, char *err_msg, char *opcode)
{
	write(2, "L", 1);
	print_number(2, line_number);
	_puts_std(2, err_msg);

	if (opcode)
		_puts_std(2, opcode);
	write(2, "\n", 1);
}
