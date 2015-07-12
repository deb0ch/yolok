/*
** printf.h for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:40:11 2015 chauvo_t
** Last update Tue Jul  7 21:40:56 2015 chauvo_t
*/

#ifndef PRINTF_H_
# define PRINTF_H_

# include "stdarg.h"

# define MSG_NULLSTRING "(nil)"

typedef struct	s_printfflags
{
  char		format_spec;
  int		(*output_fct)(va_list varargs_list);
}		t_printfflags;

int	printf_putnbr(va_list args_list);
int	printf_put_unsigned(va_list args_list);
int	printf_put_octal(va_list args_list);
int	printf_put_hexa_min(va_list args_list);
int	printf_put_hexa_maj(va_list args_list);
int	printf_put_pointer(va_list args_list);
int	printf_putchar(va_list args_list);
int	printf_putstr(va_list args_list);
int	printf_show_str(va_list args_list);
int	printf_put_binary(va_list args_list);
int	printf_put_percentchar(va_list args_list);

#endif /* !PRINTF_H_ */
