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
