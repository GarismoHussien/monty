#include "monty.h"

/**
 * mod_nodes -ths is to  add the top two elements of the stack.
 * @stack: this is a Pointer that pointing to top node of the stack.
 * @line_number: this is int type and representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


