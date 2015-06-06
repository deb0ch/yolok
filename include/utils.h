/*
** utils.h for yolo_k in /home/chauvo_t/Programming/Work_in_progress/Kernel/linux/linux_kernel
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 20:55:49 2015 chauvo_t
** Last update Sat Jun  6 12:15:29 2015 chauvo_t
*/

#ifndef UTILS_H_
# define UTILS_H_

static inline void	outb(short port, char val)
{
  asm volatile("outb %0, %1\n"
	       : /* No output */
	       : "a" (val), "d" (port));
}

static inline char	inb(short port)
{
  char	res;

  asm volatile("inb %1, %0\n"
	       : "=a" (res)
	       : "d" (port));
  return (res);
}

void	my_memset(char *b, unsigned long v, unsigned long n);

#endif /* !UTILS_H_ */
