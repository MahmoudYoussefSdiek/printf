#include "main.h"

/**
 * _printf -  function that produces output according to a format.
 *
 * @format: the format string that we will print.
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	char buffer[1024];
	va_list arg_list;
	int index = 0, printed_len = 0;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
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
					printed_len += print_char(format[index - 1]);
					printed_len += print_char(format[index]);
			}
		}
		else
			printed_len += print_char(format[index]);
		index++;
	}
	va_end(arg_list);
	return (printed_len);
}
