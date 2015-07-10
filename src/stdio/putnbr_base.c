/*
** putnbr_base.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:25:47 2015 chauvo_t
** Last update Fri Jul 10 17:49:37 2015 chauvo_t
*/

#include "stdio.h"
#include "string.h"

void	rec_putnbr_base(int nbr, char *base, int base_n, int *count)
{
	if (nbr == 0)
		return;
	rec_putnbr_base(nbr / base_n, base, base_n, count);
	*count += putchar(base[-(nbr % base_n)]);
}

int	putnbr_base(int nbr, char *base)
{
	int	count;
	int	base_n;

	base_n = strlen(base);
	count = 0;
	if (nbr == 0)
		return putchar(base[0]);
	if (nbr >= 0)
		nbr *= -1;
	else
		count += putchar('-');
	rec_putnbr_base(nbr, base, base_n, &count);
	return count;
}
