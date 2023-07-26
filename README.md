_printf()

//More info will be added here as the project continues

The code will be compiled this way:
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

Format specifier
Define the type of data to be printed on standard output. These are necessary when printing
formatted output with printf() or accepting input with scanf().

%c = used for a single character
%s = used for a string
%% = used to return the sum of all its parameters
%d = used for a signed decimal integer
%i = used for a signed decimal integer

Examples:

Characters:
_printf("%c", I);
Prints: H

Strings:
_printf("%s", "welcome");
Prints: welcome

Signed decimal integer (digit):
_printf("%d", 5);
Prints: 5

Signed decimal integer:
_printf("%i", 10);
Prints: 10

When successful, the functions return the number of the character printed (excluding
the null byte used to end output to string). If an output error is encountered, a 
negative value is returned.

Authorized functions and macros:

write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)

