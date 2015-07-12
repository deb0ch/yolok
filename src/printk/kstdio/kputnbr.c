/*
** kputnbr.c for yolok in yolok/src/printk/kstdio
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 20:59:12 2015 chauvo_t
** Last update Sun Jul 12 16:57:11 2015 chauvo_t
*/

#include "kstdio.h"
#include "string.h"

int	kputnbr(int nb)
{
	long	nbr;
	long	i;
	short	count;

	count = 0;
	nbr = nb;
	i = 1;
	if (nb < 0)
	{
		count += kputchar('-');
		nbr = -nbr;
	}
	while (i <= nbr / 10)
		i *= 10;
	while (i >= 1)
	{
		count += kputchar('0' + nbr / i);
		nbr %= i;
		i /= 10;
	}
	return count;
}
