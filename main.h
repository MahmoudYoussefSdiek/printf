#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct pair_function_symbol
{
	char symbol;
	int (*function)(va_list);
};
typedef struct pair_function_symbol call_function;

int _printf(const char *format, ...);
int print_char(char character);
int print_string(char *string);
void int_to_string(int number, char *buffer);

#endif
