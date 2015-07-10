/*
** strcmp.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:09:13 2015 chauvo_t
** Last update Tue Jul  7 21:18:38 2015 chauvo_t
*/

#include "string.h"

int	strcmp(register char *s1, register char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return *s1 - *s2;
}
