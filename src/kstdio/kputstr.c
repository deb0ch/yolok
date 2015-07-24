/*
** kputstr.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:24:12 2015 chauvo_t
** Last update Wed Jul 22 11:23:55 2015 deb0ch
*/

#include "kwrite.h"
#include "string.h"

int	kputstr(char *str)
{
	kwrite(KWRITE_ALL, str, strlen(str));
	return strlen(str);
}
