/*
** printk.c for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 15:26:35 2015 chauvo_t
** Last update Thu Jun 25 20:42:00 2015 chauvo_t
*/

#include "printk.h"
#include "serial.h"
#include "utils.h"
#include "vga.h"

void	printk_vga(const char *msg)
{
	vga_text_char_t		c;
	int			i;

	c.vga.fg_color_rgb = 7;
	c.vga.fg_color_intensity = 0;
	c.vga.bg_color_rgb = 0;
	c.vga.bg_color_intensity = 0;
	i = 0;
	while (*msg)
	{
		c.vga.ascii_code = *msg;
		*((vga_text_char_t*)VGA_BASE + i) = c;
		++msg;
		++i;
	}
}

/*
 * @Todo: write a send and a recv function, interrupt driven, to be less dirty.
 */
void	printk_serial(const char *msg)
{
	lsr_register_t	lsr;

	while (*msg)
	{
		lsr.byte = inb(COM1 + LSR);
		if (lsr.reg.thr_empty)
		{
			outb(COM1 + THR, *msg);
			++msg;
		}
	}
}

void	printk(const char *msg)
{
	printk_vga(msg);
	printk_serial(msg);
}
