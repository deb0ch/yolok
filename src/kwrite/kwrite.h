/*
** kwrite.h for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 15:37:47 2015 chauvo_t
** Last update Fri Jul 24 14:41:21 2015 deb0ch
*/

#ifndef KWRITE_H_
# define KWRITE_H_

# include "types.h"

# define KWRITE_NONE	0
# define KWRITE_DEFAULT	1
# define KWRITE_VGA	2
# define KWRITE_SERIAL	4
# define KWRITE_ALL	-1

void	vga_clr();
void	vga_scroll();
void	kwrite_vga_coord(uint32_t x, uint32_t y, char c);
void	kwrite_vga(const char *buf, size_t size);
void	kwrite_serial(const char *buf, size_t size);
void	kwrite(unsigned dst, const char *buf, size_t size);

#endif /* !KWRITE_H_ */
