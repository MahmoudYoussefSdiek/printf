#include "main.h"

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
