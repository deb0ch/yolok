/*
** stdarg.h for yolok in /home/chauvo_t/Programming/Work_in_progress/Kernel/kfs/kfs-chauvo_t
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 20:06:20 2015 chauvo_t
** Last update Tue Jul  7 20:06:48 2015 chauvo_t
*/

#ifndef STDARG_H_
# define STDARG_H_

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#define va_copy(d,s)	__builtin_va_copy(d,s)

typedef __builtin_va_list va_list;

#endif /* !STDARG_H_ */
