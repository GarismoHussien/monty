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

