/*
** kputchar.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun Jul 12 16:00:56 2015 chauvo_t
** Last update Wed Jul 22 11:23:11 2015 deb0ch
*/

#include "kwrite.h"

int	kputchar(char c)
{
	char	buf[2];

	*buf = c;
	buf[1] = 0;
	kwrite(KWRITE_ALL, buf, 1);
	return 1;
}
