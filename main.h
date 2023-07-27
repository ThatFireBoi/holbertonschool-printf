#ifndef __MAIN__
#define __MAIN__
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/*Prototype for _printf function, prints to formated output*/
int _printf(const char *format, ...);

/*Prototype for _putchar, writes a character*/
int _putchar(char c);

/*Character function declaration*/
int print_char(va_list args);

/*String function declaration*/
int print_string(va_list args);

/*Integer function declaration*/
int print_integer(va_list args);

typedef struct
{
  char specifier;
  int (*handler)(va_list);
} FormatHandler;

#endif
