#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct instruction_s - opcode n its function
 * @opcode: opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its F
 * for stack, queues, FIFO, LIFO
 */
typedef struct instruction_s
{
 char *opcode;
 void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
/*file operation*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*String operation*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
/*Math operation with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);
/**
 * struct stack_s - doubly linked list representation j stack
 * @n: integerrr
 * @prev: points to  prev element of the stack 
 * @next: points to the next element of the stack 
 *
 * Description: doubly linked listtt nodee structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
#endif
