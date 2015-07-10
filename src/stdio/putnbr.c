/*
** putnbr.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 20:59:12 2015 chauvo_t
** Last update Fri Jul 10 17:49:58 2015 chauvo_t
*/

#include "stdio.h"
#include "string.h"

int	putnbr(int nb)
{
	long	nbr;
	long	i;
	short	count;

	count = 0;
	nbr = nb;
	i = 1;
	if (nb < 0)
	{
		count += putchar('-');
		nbr = -nbr;
	}
	while (i <= nbr / 10)
		i *= 10;
	while (i >= 1)
	{
		count += putchar('0' + nbr / i);
		nbr %= i;
		i /= 10;
	}
	return count;
}
