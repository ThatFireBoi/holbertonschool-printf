#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string containing format specifier
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	FormatHandler formatHandlers[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_integer},
		{'i', print_integer},
		{'b', print_binary},
		{'\0', NULL}
	};
	va_list args;
	int count = 0;
	int i = 0;
	int j;
	int foundHandler;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[++i] == ' ')
				;
			foundHandler = 0;
			for (j = 0; formatHandlers[j].specifier != '\0'; j++)
			{
				if (format[i] == formatHandlers[j].specifier)
				{
					count += formatHandlers[j].handler(args);
					foundHandler = 1;
					break;
				}
			}
			if (!foundHandler)
			{
				if (format[i] == '%')
					count += write(1, "%", 1);
				else
				{
					count += write(1, "%r", 2);
				}
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
