#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Print formatted output to the standard output
 * @format: Format string with conversion specifiers
 *
 * This function handles the specifiers %c, %s, %%, %d and %i
 * using a table of function pointers.
 *
 * Return: The number of characters printed, or -1 on error
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list args;
	printer_t printer[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'\0', NULL}};
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			j = 0;
			while (printer[j].index != '\0')
			{
				if (format[i + 1] == printer[j].index)
				{
					len += printer[j].print(args);
					i += 2;
					break;
				}
				j++;
			}
			if (printer[j].index == '\0')
			{
				len += _putchar('%');
				len += _putchar(format[i + 1]);
				i += 2;
			}
		}
	}
	va_end(args);
	return (len);
}
