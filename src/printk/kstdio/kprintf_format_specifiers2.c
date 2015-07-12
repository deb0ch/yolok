/*
** printf_format_specifiers2.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:26:26 2015 chauvo_t
** Last update Sun Jul 12 16:56:48 2015 chauvo_t
*/

#include "stdarg.h"
#include "kstdio.h"
#include "string.h"
#include "types.h"

int	kprintf_put_pointer(va_list args_list)
{
	int		count;
	void		*ptr;

	count = 0;
	ptr = va_arg(args_list, void*);
	if (ptr == 0)
		return (kputstr(MSG_NULLSTRING));
	count += kputstr("0x");
	return count + kputunslong_base((unsigned long)ptr, "0123456789abcdef");
}

int	kprintf_putchar(va_list args_list)
{
	return kputchar(va_arg(args_list, int));
}

int	kprintf_putstr(va_list args_list)
{
	char	*str;

	str = va_arg(args_list, char*);
	if (str == NULL)
		return kputstr(MSG_NULLSTRING);
	return kputstr(str);
}

int	kprintf_show_str(va_list args_list)
{
	int	i;
	int	count;
	char	*str;

	str = va_arg(args_list, char*);
	if (str == NULL)
		return kputstr(MSG_NULLSTRING);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += kputchar('\\');
			if (str[i] < 64)
				count += kputchar('0');
			if (str[i] < 8)
				count += kputchar('0');
			count += kputnbr_base(str[i], "01234567");
		}
		else
			count += kputchar(str[i]);
		i += 1;
	}
	return count;
}

int	kprintf_put_binary(va_list args_list)
{
	return kputnbr_base(va_arg(args_list, int), "01");
}
