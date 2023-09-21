#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 100

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_var_s - global vars used in this project
 * @number: integer number to add to stack
 * @args: pointer to pointer
 *@o_opfile: file stream
 *@line: pointer that conatin line readed from file (used by getline)
 *@mode: the format of the data 'q' queue or 's' stack
 */
typedef struct global_var_s
{
int number;
char *line;
char **args;
FILE *o_opfile;
char mode;
} globals_var;

extern globals_var vars;
int __putchar(char c);
void closefile(FILE *file);
char **strtok_alloc(char *line, ssize_t read);
void print_number(int std, int n);
int _puts(char *c);
int _atoi(char *argument, stack_t *stack, int line_count);
int _puts_std(int std, char *str);
int _slen(char *s);
int p_err_getline(void);
void p_err_write(int w);
void print_error(int line_number, char *err_msg, char *opcode);
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number);
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);
void pchar_func(stack_t **stack, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);
void rotl_func(stack_t **stack, unsigned int line_number);
void rotr_func(stack_t **stack, unsigned int line_number);

char *_strdup(const char *str);
void free_stack(stack_t **stack);
void free_all(stack_t **stack);




#endif /* MONTY_H */
