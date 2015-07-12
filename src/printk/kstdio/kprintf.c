/*
** printf.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:29:12 2015 chauvo_t
** Last update Sun Jul 12 17:04:15 2015 chauvo_t
*/

#include "kprintf.h"
#include "stdarg.h"
#include "kstdio.h"
#include "string.h"
#include "types.h"

static t_kprintfflags	g_kprintf_formspecs[] =
{
	{'d', kprintf_putnbr},
	{'i', kprintf_putnbr},
	{'u', kprintf_put_unsigned},
	{'o', kprintf_put_octal},
	{'x', kprintf_put_hexa_min},
	{'X', kprintf_put_hexa_maj},
	{'p', kprintf_put_pointer},
	{'c', kprintf_putchar},
	{'s', kprintf_putstr},
	{'S', kprintf_show_str},
	{'b', kprintf_put_binary},
	{'%', kprintf_put_percentchar},
	{'\0', NULL}
};

int	kprintf_put_percentchar(va_list args_list)
{
	(void)args_list;
	return kputchar('%');
}

static int	call_formspecs(char *format, int i, va_list varargs_list)
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while ((g_kprintf_formspecs[j]).format_spec != '\0')
	{
		if ((g_kprintf_formspecs[j]).format_spec == format[i])
		{
			count += (g_kprintf_formspecs[j]).output_fct(varargs_list);
			return count;
		}
		j += 1;
	}
	if (g_kprintf_formspecs[j].format_spec == '\0')
	{
		count += kputchar('%');
		count += kputchar(format[i]);
	}
	return count;
}

int	kprintf(char *format, ...)
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
			count += kputchar(format[i]);
		i += 1;
	}
	if (format[i] != '\0' && format[i] != '%')
		count += kputchar(format[i]);
	va_end(varargs_list);
	if (format[i] == '%')
		return -1;
	return count;
}
