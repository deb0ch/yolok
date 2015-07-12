/*
** utils.h for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 20:55:49 2015 chauvo_t
** Last update Tue Jul  7 21:49:37 2015 chauvo_t
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "types.h"

# ifndef LOW8
#  define LOW8(a)	((unsigned char)(a & 0xff))
# endif

# ifndef HIGH8
#  define HIGH8(a)	((unsigned char)((a & 0xff00) >> 8))
# endif

static inline void	outb(uint16_t port, uint8_t val)
{
	asm volatile("outb %0, %1\n"
		     : /* No output */
		     : "a" (val), "d" (port));
}

static inline char	inb(uint16_t port)
{
	uint8_t	res;

	asm volatile("inb %1, %0\n"
		     : "=a" (res)
		     : "d" (port));
	return (res);
}

void	vga_clr();

#endif /* !UTILS_H_ */
