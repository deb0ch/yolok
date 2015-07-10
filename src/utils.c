/*
** utils.c for yolo_k in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 20:56:54 2015 chauvo_t
** Last update Fri Jul 10 17:46:51 2015 chauvo_t
*/

#include "string.h"
#include "vga.h"

void	vga_clr()
{
	memset(VGA_BASE, 0, 80 * 25 * 2);
}
