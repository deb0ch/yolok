/*
** main.c for yolokernel
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri May 22 18:33:17 2015 chauvo_t
** Last update Fri Dec 18 13:27:32 2015 chauvo_t
*/

#include "asm_utils.h"
#include "interrupts.h"
#include "keyboard.h"
#include "kstdio.h"
#include "kwrite.h"
#include "pit.h"
#include "segmentation.h"
#include "serial.h"
#include "vga.h"

#define MAGIC_MULTIBOOT	0x2badb002

void    yolomain(unsigned int magic, const void *multiboot)
{
	(void)multiboot;
	kprintf("\n\nBooooooooooooting !!!\n\n");
	if (magic != MAGIC_MULTIBOOT)
	{
		kwrite(KWRITE_ALL, "error: wrong magic\n", 19);
		return ;
	}
	vga_clr();
	init_serial_port(COM1);
	init_flat_gdt();
	interrupts_init();
	keyboard_init();
	pit_init(100);
	kprintf("Interrupts initialized\n");
	asm volatile("int $0x03 \n\t");
	asm volatile("int $0x03 \n\t");
	asm volatile("int $0x03 \n\t");
	while (42)
	{
		/* kprintf("Glop !\n"); */
		/* cpu_relax(); */
	}
}
