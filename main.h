#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct printf - Struct type for format specifiers
 * @index: Character representing the format specifier
 * @print: Pointer to function that prints for this specifier
 */
typedef struct printf
{
	char index;
	int (*print)(va_list args);
} printer_t;

/**
 * _putchar - Write a character to standard output
 * @c: Character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * _printf - Print formatted output to standard output
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_digit(va_list args);
int print_int(va_list args);

#endif
