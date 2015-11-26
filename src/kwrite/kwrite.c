/*
** kwrite.c for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 15:26:35 2015 chauvo_t
** Last update Thu Nov 26 20:47:57 2015 chauvo_t
*/

#include "kwrite.h"
#include "serial.h"
#include "asm_utils.h"

unsigned g_kwrite_default = KWRITE_ALL;

/*
 * @Todo: write a send and a recv function, interrupt driven, to be less dirty.
 */
void	kwrite_serial(const char *buf, size_t size)
{
	lsr_register_t	lsr;

	while (size)
	{
		lsr.byte = inb(COM1 + LSR);
		if (lsr.reg.thr_empty)
		{
			outb(COM1 + THR, *buf);
			++buf;
			--size;
		}
	}
}

void	kwrite(unsigned dst, const char *buf, size_t size)
{
	if (g_kwrite_default == KWRITE_DEFAULT)
		g_kwrite_default = KWRITE_ALL;
	switch (dst)
	{
	case KWRITE_DEFAULT:
		kwrite(g_kwrite_default, buf, size);
		break;
	case KWRITE_VGA:
		kwrite_vga(buf, size);
		break;
	case KWRITE_SERIAL:
		kwrite_serial(buf, size);
		break;
	case KWRITE_ALL:
		kwrite_vga(buf, size);
		kwrite_serial(buf, size);
		break;
	default:
		break;
	}
}
