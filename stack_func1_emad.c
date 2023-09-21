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

