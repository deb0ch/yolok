/*
** kprintf.h for yolok in yolok/src/printk/kprintf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:40:11 2015 chauvo_t
** Last update Sun Jul 12 17:03:50 2015 chauvo_t
*/

#ifndef KPRINTF_H_
# define KPRINTF_H_

# include "stdarg.h"

# define MSG_NULLSTRING "(nil)"

typedef struct	s_kprintfflags
{
  char		format_spec;
  int		(*output_fct)(va_list varargs_list);
}		t_kprintfflags;

int	kprintf_putnbr(va_list args_list);
int	kprintf_put_unsigned(va_list args_list);
int	kprintf_put_octal(va_list args_list);
int	kprintf_put_hexa_min(va_list args_list);
int	kprintf_put_hexa_maj(va_list args_list);
int	kprintf_put_pointer(va_list args_list);
int	kprintf_putchar(va_list args_list);
int	kprintf_putstr(va_list args_list);
int	kprintf_show_str(va_list args_list);
int	kprintf_put_binary(va_list args_list);
int	kprintf_put_percentchar(va_list args_list);

#endif /* !KPRINTF_H_ */
