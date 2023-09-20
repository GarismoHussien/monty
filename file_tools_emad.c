#include "monty.h"
/**
 * read_file - this function is to read a file
 * @fd: this is a pointer to point to the file descriptor
 * Return: always return void
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}
/**
 * parse_line - this function is to separate each line into tokens to determine
 * which function to call
 * @buffer: this is a pointer that points to line from the file
 * @line_number: this is the line number
 * @format:  this is int type,storage format. If 0 Nodes will be entered as a stack.
 * if 1 node will be entered as a queue.
 * Return: always returns 0 if the opcode is stack. or 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}
/**
 * find_func - this function is to find the appropriate function for the opcode
 * @opcode: this is a pointer opcode
 * @value: this is a pointer char type argument of opcode
 * @format:  thisis int type storage format. If 0 Nodes will be entered as a stack.
 * @ln: this is int type and line number
 * if 1 node will be entered as a queue.
 * Return: always return void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}
/**
 * call_fun - this function is to Call the required function.
 * @func: this is a Pointer that points to the function that is about to be called.
 * @op: is a pointer char type and string representing the opcode.
 * @val: this is apointer char type and string representing a numeric value.
 * @ln: this is int type and line numeber for the instruction.
 * @format: this is int type and format specifier. If 0 Nodes will be entered as a stack.
 * if 1 node will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

