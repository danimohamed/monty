#include "monty.h"

globals_var vars = {0, NULL, NULL, NULL, 's'};

/**
 * closefile - function that close file stream.
 * @file: file to close
 */

void closefile(FILE *file)
{

	if (fclose(file) == EOF)
	{
		fprintf(stderr, "Error: Can't close file\n");
		exit(EXIT_FAILURE);
	}

}
/**
 * main - program that copies the content of a file to another file.
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char  *opfile = NULL, **args = NULL, *line = NULL;
	ssize_t read = 0;
	size_t len = 0;
	FILE *o_opfile = NULL;
	int line_count = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{ fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	opfile = argv[1];
	o_opfile = fopen(opfile, "r");
	vars.o_opfile = o_opfile;
	if (vars.o_opfile == NULL)
	{ fprintf(stderr, "Error: Can't open file %s\n", opfile);
		exit(EXIT_FAILURE); }
while ((read = getline(&line, &len, o_opfile)) != -1)
	{   line_count++;
		vars.line = line;
		args = strtok_alloc(line, read);
		vars.args = args;
		if (!vars.args || vars.args[0][0] == '#' ||
		(strcmp(vars.args[0], "nop") == 0))
			{
			if (vars.args)
			free(vars.args);
			continue; }
if (strcmp(vars.args[0], "stack") == 0 || strcmp(vars.args[0], "queue") == 0)
	{ vars.mode = (strcmp(vars.args[0], "stack") == 0) ? 's' : 'q';
			free(vars.args);
			continue; }
		if (strcmp(vars.args[0], "push") == 0)
			vars.number = _atoi(vars.args[1], stack, line_count);
		execute_opcode(&stack, vars.args[0], line_count);
		free(vars.args), free(line);
		line = NULL; }
	if (stack)
	free_stack(&stack), free(line);
	closefile(vars.o_opfile);
	return (0);
}
