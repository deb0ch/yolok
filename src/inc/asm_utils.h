/*
** asm_utils.h for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 20:55:49 2015 chauvo_t
** Last update Fri Nov 27 11:50:35 2015 chauvo_t
*/

#ifndef ASM_UTILS_H_
# define ASM_UTILS_H_

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

static inline void	outw(uint16_t port, uint16_t val)
{
	asm volatile("outw %0, %1\n"
		     : /* No output */
		     : "a" (val), "d" (port));
}

static inline uint16_t	inw(uint16_t port)
{
	uint16_t	res;

	asm volatile("inw %1, %0\n"
		     : "=a" (res)
		     : "d" (port));
	return (res);
}

static inline void	outl(uint16_t port, uint32_t val)
{
	asm volatile("outl %0, %1\n"
		     : /* No output */
		     : "a" (val), "d" (port));
}

static inline uint32_t	inl(uint16_t port)
{
	uint32_t	res;

	asm volatile("inl %1, %0\n"
		     : "=a" (res)
		     : "d" (port));
	return (res);
}

static inline void disable_interrupt()
{
	asm volatile("cli");
}

static inline void enable_interrupt()
{
	asm volatile("sti");
}

/*
 * REP NOP (PAUSE) is a good thing to insert into busy-wait loops.
 * The rep; nop instruction sequence is actually equivalent to the
 * `pause` instruction, not supported by all assemblers, in the
 * generated machine opcodes.
 */
static inline void cpu_relax(void)
{
	asm volatile("rep; nop" ::: "memory");
}

#endif /* !ASM_UTILS_H_ */
