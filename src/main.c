/*
** main.c for yolokernel in kfs-chauvo_t/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri May 22 18:33:17 2015 chauvo_t
** Last update Sat Oct 31 16:54:51 2015 chauvo_t
*/

#include "kwrite.h"
#include "segmentation.h"
#include "serial.h"
#include "utils.h"
#include "vga.h"

#define MAGIC_MULTIBOOT	0x2badb002

void    yolomain(unsigned int magic, const void *multiboot)
{
	(void)multiboot;
	if (magic != MAGIC_MULTIBOOT)
	{
		kwrite(KWRITE_ALL, "error: wrong magic\n", 19);
		return ;
	}
	vga_clr();
	init_serial_port(COM1);
	while (42)
		kwrite(KWRITE_ALL, "Yoloooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo !\n", 54);
	init_flat_gdt();
}
