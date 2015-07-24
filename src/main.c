/*
** main.c for yolokernel in kfs-chauvo_t/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri May 22 18:33:17 2015 chauvo_t
** Last update Fri Jul 24 17:03:15 2015 deb0ch
*/

#include "kwrite.h"
#include "segmentation.h"
#include "serial.h"
#include "utils.h"
#include "vga.h"

void    yolomain()
{
	vga_clr();
	init_serial_port(COM1);
	while (42)
		kwrite(KWRITE_ALL, "Yoloooooooooooooooooooooooooooooooooooooooooooooooo !\n", 54);
	init_flat_gdt();
}
