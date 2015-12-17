/*
** kprintf_format_specifiers1.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:07:12 2015 chauvo_t
** Last update Sun Nov 29 13:03:24 2015 chauvo_t
*/

#include "kprintf.h"
#include "kstdio.h"
#include "stdarg.h"
#include "string.h"
#include "types.h"

int	kprintf_putnbr(va_list args_list)
{
	return kputnbr(va_arg(args_list, int));
}

int	kprintf_put_unsigned(va_list args_list)
{
	unsigned int	nb;
	long		nbr;
	long		i;
	short		count;

	nb = va_arg(args_list, unsigned int);
	count = 0;
	nbr = nb;
	i = 1;
	while (i <= nbr / 10)
		i *= 10;
	while (i >= 1)
	{
		count += kputchar('0' + nbr / i);
		nbr %= i;
		i /= 10;
	}
	return count;
}

int	kprintf_put_octal(va_list args_list)
{
	return kputunsint_base(va_arg(args_list, int), "01234567");
}

int	kprintf_put_hexa_min(va_list args_list)
{
	return kputunsint_base(va_arg(args_list, int), "0123456789abcdef");
}

int	kprintf_put_hexa_maj(va_list args_list)
{
	return kputunsint_base(va_arg(args_list, int), "0123456789ABCDEF");
}

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
