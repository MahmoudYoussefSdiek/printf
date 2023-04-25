#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(char character);
int print_string(char *string);
void int_to_string(int number, char *buffer);

#endif
