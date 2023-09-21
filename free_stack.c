#include "monty.h"
/**
 * free_stack - function that frees a stack.
 * @stack: pointer to linked lists
 */
void free_stack(stack_t **stack)
{
if (stack)
	{
	if (*stack)
		{
		while ((*stack)->next)
		{
			(*stack) = (*stack)->next;
			free((*stack)->prev);
		}
		free((*stack));
		(*stack) = NULL;
		}
	}
}
/**
* free_all - function that frees a stack, line, args and close the file stream.
 * @stack: pointer to linked lists
*
*/
void free_all(stack_t **stack)
{
	free_stack(stack);
	free(vars.args);
	free(vars.line);
	closefile(vars.o_opfile);
}
