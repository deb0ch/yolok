/*
** kputchar.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun Jul 12 16:00:56 2015 chauvo_t
** Last update Sun Jul 12 16:01:16 2015 chauvo_t
*/

#include "printk.h"

int	kputchar(char c)
{
	char	buf[2];

	*buf = c;
	buf[1] = 0;
	printk(buf);
	return 1;
}
