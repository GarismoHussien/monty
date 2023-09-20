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

