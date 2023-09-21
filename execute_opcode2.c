#include "monty.h"

/**
 * add_func - function that adds the top two elements of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void add_func(stack_t **stack,  unsigned int line_number)
{

	if (stack == NULL)
		exit(EXIT_FAILURE);
	if (!(*stack) || !((*stack)->next))
	{ fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE); }
	(*stack)->next->n += (*stack)->n;
	pop_func(stack, line_number);
}
/**
 * div_func - function that divides the second top element of the stack by
 * the top element of the stack
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void div_func(stack_t **stack,  unsigned int line_number)
{

	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if (!(*stack) || !((*stack)->next))
	{ fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE); }

	else if (!(*stack)->n)
	{ fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE); }
	else
	{
		(*stack)->next->n /= (*stack)->n;
		pop_func(stack, line_number);
	}
}

/**
 * mod_func - function that computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void mod_func(stack_t **stack,  unsigned int line_number)
{
	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if (!(*stack)->n)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		pop_func(stack, line_number);
	}
}

/**
 * pchar_func - function that prints the char at the top of the stack,
 * followed by a new line.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			free_all(stack);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", (*stack)->n);
	}
}

/**
 * pstr_func - function that prints the char at the top of the stack,
 * followed by a new line
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if ((*stack))
	{
	for (tmp = *stack; tmp && tmp->n > 0 && tmp->n <= 127 ; tmp = tmp->next)
		printf("%c", tmp->n);
	}
	printf("\n");
}
