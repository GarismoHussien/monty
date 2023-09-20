#include "monty.h"

/**
 * create_node - this is to create a node.
 * @n: this is int type and number to go inside the node.
 * Return: if sucess a pointer to the node. or  NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

