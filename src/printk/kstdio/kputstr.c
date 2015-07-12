/*
** kputstr.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:24:12 2015 chauvo_t
** Last update Sun Jul 12 16:00:21 2015 chauvo_t
*/

#include "printk.h"
#include "string.h"

int	kputstr(char *str)
{
	printk(str);
	return strlen(str);
}
