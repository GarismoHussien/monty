#include "monty.h"


/**
 * nop - this function is to Do nothing.
 * @stack: this is a Pointer that  pointing to top node of the stack.
 * @line_number: this is int type and  representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * add_nodes - this function is to add the top two elements of the stack.
 * @stack: ti is a pointer Pointer to that pointing to top node of the stack.
 * @line_number: this is int type and  representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

