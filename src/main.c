/*
** main.c for yolokernel in kfs-chauvo_t/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri May 22 18:33:17 2015 chauvo_t
** Last update Thu Jun 25 16:06:52 2015 chauvo_t
*/

#include "printk.h"
#include "segmentation.h"
#include "serial.h"
#include "utils.h"
#include "vga.h"

void    yolomain()
{
	vga_clr();
	init_serial_port(COM1);
	printk("Yolooo ! ");
	init_flat_gdt();
}
