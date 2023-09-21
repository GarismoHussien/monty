#include "monty.h"

/**
 * print_stack - ths is to adds a node to the stack.
 * @stack: this is a pointer that pointing to top node of the stack.
 * @line_number: this is int type line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pop_top - this function is to add a node to the stack.
 * @stack: this is a Pointer that  pointing to top node of the stack.
 * @line_number: this is int type Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * print_top - this function is to Print the top node of the stack.
 * @stack: this is a pointer to that  pointing to top node of the stack.
 * @line_number: this is int type and  representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

