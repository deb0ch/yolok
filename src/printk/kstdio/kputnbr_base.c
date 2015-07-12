/*
** kputnbr_base.c for yolok in yolok/src/printk/kstdio
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:25:47 2015 chauvo_t
** Last update Sun Jul 12 16:03:45 2015 chauvo_t
*/

#include "kstdio.h"
#include "string.h"

static void	rec_kputnbr_base(int nbr, char *base, int base_n, int *count)
{
	if (nbr == 0)
		return;
	rec_kputnbr_base(nbr / base_n, base, base_n, count);
	*count += kputchar(base[-(nbr % base_n)]);
}

int	kputnbr_base(int nbr, char *base)
{
	int	count;
	int	base_n;

	base_n = strlen(base);
	count = 0;
	if (nbr == 0)
		return kputchar(base[0]);
	if (nbr >= 0)
		nbr *= -1;
	else
		count += kputchar('-');
	rec_kputnbr_base(nbr, base, base_n, &count);
	return count;
}
