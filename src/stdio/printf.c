/*
** printf.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:29:12 2015 chauvo_t
** Last update Fri Jul 10 17:47:38 2015 chauvo_t
*/

#include "printf.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "types.h"

static t_printfflags	g_printf_formspecs[] =
{
	{'d', printf_putnbr},
	{'i', printf_putnbr},
	{'u', printf_put_unsigned},
	{'o', printf_put_octal},
	{'x', printf_put_hexa_min},
	{'X', printf_put_hexa_maj},
	{'p', printf_put_pointer},
	{'c', printf_putchar},
	{'s', printf_putstr},
	{'S', printf_show_str},
	{'b', printf_put_binary},
	{'%', printf_put_percentchar},
	{'\0', NULL}
};

int	printf_put_percentchar(va_list args_list)
{
	(void)args_list;
	return putchar('%');
}

int	call_formspecs(char *format, int i, va_list varargs_list)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while ((g_printf_formspecs[j]).format_spec != '\0')
	{
		if ((g_printf_formspecs[j]).format_spec == format[i])
		{
			count += (g_printf_formspecs[j]).output_fct(varargs_list);
			return count;
		}
		j += 1;
	}
	if (g_printf_formspecs[j].format_spec == '\0')
	{
		count += putchar('%');
		count += putchar(format[i]);
	}
	return count;
}

int	printf(char *format, ...)
{
	int		i;
	int		count;
	va_list		varargs_list;

	va_start(varargs_list, format);
	count = 0;
	i = 0;
	while (format[i] != '\0' && format[i + 1] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			count += call_formspecs(format, i, varargs_list);
		}
		else
			count += putchar(format[i]);
		i += 1;
	}
	if (format[i] != '\0' && format[i] != '%')
		count += putchar(format[i]);
	va_end(varargs_list);
	if (format[i] == '%')
		return -1;
	return count;
}
