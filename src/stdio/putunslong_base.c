/*
** putunslong_base.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:23:24 2015 chauvo_t
** Last update Fri Jul 10 17:51:20 2015 chauvo_t
*/

#include "stdio.h"
#include "string.h"

void	rec_putunslong_base(unsigned long nbr, char *base, int *count)
{
	int	base_n;

	base_n = strlen(base);
	if (nbr == 0)
		return;
	rec_putunslong_base(nbr / base_n, base, count);
	*count += putchar(base[nbr % base_n]);
}

int	putunslong_base(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return putchar(base[0]);
	rec_putunslong_base(nbr, base, &count);
	return count;
}