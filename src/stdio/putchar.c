/*
** my_putchar.c for libmy in /home/chauvo_t/rendu/Piscine-C-Jour_03
**
** Made by a
** Login   <chauvo_t@epitech.net>
**
** Started on  Wed Oct  2 10:05:51 2013 a
** Last update Tue Jul  7 21:32:23 2015 chauvo_t
*/

#include "printk.h"

int	putchar(char c)
{
	char	buf[2];

	*buf = c;
	buf[1] = 0;
	printk(buf);
	return 1;
}
