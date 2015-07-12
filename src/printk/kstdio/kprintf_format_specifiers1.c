/*
** kprintf_format_specifiers1.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:07:12 2015 chauvo_t
** Last update Sun Jul 12 15:59:26 2015 chauvo_t
*/

#include "kstdio.h"
#include "stdarg.h"
#include "string.h"

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
