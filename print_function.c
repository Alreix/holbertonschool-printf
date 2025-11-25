#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int print_char(va_list args)
{
	int len = 0;
	char character = va_arg(args, int);
	len += _putchar(character);
	return(len);
}

int print_string(va_list args)
{
	int len = 0;
	char *string = va_arg(args, char *);

	if (string == NULL)
		return (0);
	while (string[len])
		len += _putchar(string[len]);
		
	return(len);
}

int print_percent(va_list args)
{
	int len = 0;
	(void)args;
	len += _putchar('%');
	return (len);
}

int print_int_helper(int num)
{
	int len = 0;
	if (num / 10)
        len += print_int_helper(num / 10);

    _putchar('0' + (num % 10));
	return (len);
}

int print_int(va_list args)
{
	int len = 0;
	int num = va_arg(args, int);

	if (num == 0)
		return(len);

	if (num < 0)
	{
		len += _putchar('-');
		num = -num;
	}

	if (num >= 10)
		len += print_int_helper(num);
		
	return(len);
}
