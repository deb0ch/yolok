/*
** putstr.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:24:12 2015 chauvo_t
** Last update Fri Jul 10 17:50:28 2015 chauvo_t
*/

#include "printk.h"
#include "string.h"

int	putstr(char *str)
{
	printk(str);
	return strlen(str);
}
