#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * print_char - Conversion and printing of characters
 *
 * @args: va_list containing the character to be printed
 *
 * Return: number of characters printed, 1.
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Conversion and printing of strings
 *
 * @args: va_list containing the string to be printed
 *
 * Return: number of characters printed, not the NULL byte
 */

int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int length = 0;

	while (str[length])
		length++;
	return (write(1, str, length));
}

/**
 * print_integer - Conversion and printing of integers
 *
 * @args: va_list containing the integer to be printed
 *
 * Return: number of integers printed
 */

int print_integer(va_list args)
{
	int num = va_arg(args, int);

	char buffer[20];
	int length = sprintf(buffer, "%d", num);
	return (write(1, buffer, length));
}

/**
 * print_binary - Conversion and printing of binary numbers
 *
 * @args: va_list containing the integer to be printed un binary
 *
 * Return: number of characters printed
 */

int print_binary(va_list args)
{
	int num = va_arg(args, int);
	char buffer[33];
	int count = 0;
	int index = 0;
	int i;
	int j;
	int isNegative = 0;

	if (num == 0)
	{
		buffer[index++] = '0';
	}
	else
	{
		if (num < 0)
		{
			isNegative = 1;
			num = -num;
		}

		while (num != 0)
		{
			buffer[index++] = (num & 1) ? '1' : '0';
			num >>= 1;
		}

		while (index < 32)
		{
			buffer[index++] = '0';
		}

		for (i = isNegative, j = index - 1; i < j; i++, j--)
		{
			char temp = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp;
		}

		if (isNegative)
		{
			buffer[0] = '-';
		}
	}

	buffer[index] = '\0';
	count += write(1, buffer, index);

	return (count);
}
