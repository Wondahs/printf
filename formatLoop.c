#include "main.h"

/**
 * formatLoop - Handles formatting and printing
 * @format: The format string
 * @args: List of arguments
 * @pchar: Pointer to the character count
 *
 * Return: Number of printed characters(Excluding string terminator
 */
int formatLoop(const char *format, va_list args, int *pchar)
{
	FormatHandlerInfo formatHandlers[] = HANDLERS;
	void (*handler)(va_list, int *) = NULL;
	unsigned long int i;
	int ret = *pchar;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ret++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			if (*format != '%')
			{
				for (i = 0; i < sizeof(formatHandlers) / sizeof(formatHandlers[0]); i++)
				{
					if (*format == formatHandlers[i].specifier)
					{
						handler = formatHandlers[i].handler;
						break;
					}
				}
				if (handler)
					handler(args, pchar);
				else
					handle_Char((char *)format, pchar);
			}
			else
				handle_perc(&ret);
		}
		format++;
	}
	return (ret += *pchar);
}
