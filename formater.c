#include "main.h"

/**
 *handleChar - Handles printing of char
 *@args: Args
 *@pchar: Pointer to number of characters printed
 *
 *Return: Nothing
 */
void handleChar(va_list args, int *pchar)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*pchar)++;
}

/**
 *handleString - Handles printing of string
 *@args: Args
 *@pchar: Pointer to number of characters printed
 *
 *Return: Nothing
 */
void handleString(va_list args, int *pchar)
{
	char *str = va_arg(args, char *);

	*pchar += print_str(str);
}

/**
 *handleInt - Handles printing of integer
 *@args: Args
 *@pchar: Pointer to number of characters printed
 *
 *Return: Nothing
 */
void handleInt(va_list args, int *pchar)
{
	int num = va_arg(args, int);

	*pchar += print_int(num);
}
