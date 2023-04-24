#include "main.h"

/**
 * int_to_string - function that take int and save it in array as string.
 *
 * @number: number that we will save it as string.
 * @buffer: array that we will save the string.
 *
 * Return: void.
 */
void int_to_string(int number, char *buffer)
{
	sprintf(buffer, "%d", number);
}

/**
 * print_char - function that prints a character to standard output.
 *
 * @character: the character that we will print.
 *
 * Return: 1 on success or -1 on error
 */
int print_char(char character)
{
	return (write(1, &character, 1));
}

/**
 * print_string - prints a string to standard output.
 *
 * @string: the string that we will print.
 *
 * Return: number of characters printed (string length)
 */
int print_string(char *string)
{
	int index = 0;

	if (string == NULL)
		string = "(null)";

	while (string[index] != '\0')
	{
		print_char(string[index]);
		index++;
	}

	return (index);
}
/**
 * _printf -  function that produces output according to a format.
 *
 * @format: the format string that we will print.
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int index = 0, printed_len = 0;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			switch (format[index])
			{
				case 'c':
					printed_len += print_char(va_arg(arg_list, int));
					break;
				case 's':
					printed_len += print_string(va_arg(arg_list, char *));
					break;
				case '%':
					printed_len += print_char('%');
					break;
				case 'd':
				case 'i':
					int_to_string(va_arg(arg_list, int), buffer);
					printed_len += print_string(buffer);
					break;
				default:
					return (-1);
			}
		}
		else
			printed_len += print_char(format[index]);
		index++;
	}
	va_end(arg_list);
	return (printed_len);
}
