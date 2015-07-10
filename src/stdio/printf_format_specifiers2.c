/*
** printf_format_specifiers2.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:26:26 2015 chauvo_t
** Last update Fri Jul 10 17:48:59 2015 chauvo_t
*/

#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "types.h"

int	printf_put_pointer(va_list args_list)
{
	int		count;
	void		*ptr;

	count = 0;
	ptr = va_arg(args_list, void*);
	if (ptr == 0)
		return (putstr(MSG_NULLSTRING));
	count += putstr("0x");
	return count + putunslong_base((unsigned long)ptr, "0123456789abcdef");
}

int	printf_putchar(va_list args_list)
{
	return putchar(va_arg(args_list, int));
}

int	printf_putstr(va_list args_list)
{
	char	*str;

	str = va_arg(args_list, char*);
	if (str == NULL)
		return putstr(MSG_NULLSTRING);
	return putstr(str);
}

int	printf_show_str(va_list args_list)
{
	int	i;
	int	count;
	char	*str;

	str = va_arg(args_list, char*);
	if (str == NULL)
		return putstr(MSG_NULLSTRING);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += putchar('\\');
			if (str[i] < 64)
				count += putchar('0');
			if (str[i] < 8)
				count += putchar('0');
			count += putnbr_base(str[i], "01234567");
		}
		else
			count += putchar(str[i]);
		i += 1;
	}
	return count;
}

int	printf_put_binary(va_list args_list)
{
	return putnbr_base(va_arg(args_list, int), "01");
}
