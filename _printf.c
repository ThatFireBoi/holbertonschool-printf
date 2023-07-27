#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 *
 *
 *
 *
 *
 */

FormatHandler formatHandlers[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_integer},
	{'i', print_integer},
	{'\0', NULL}
};

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;
	int j;
	int foundHandler;

	if (format == NULL)
		return -1;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[++i] == ' ');

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
				count += write(1, &format[i - 1], 1);
			}
		}

		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return count;
}
