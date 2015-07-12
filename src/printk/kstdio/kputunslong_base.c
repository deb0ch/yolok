/*
** kputunslong_base.c for yolok in yolok/src/printk/kstdio/
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:23:24 2015 chauvo_t
** Last update Sun Jul 12 17:02:01 2015 chauvo_t
*/

#include "kstdio.h"
#include "string.h"

static void	rec_kputunslong_base(unsigned long nbr, char *base, int *count)
{
	int	base_n;

	base_n = strlen(base);
	if (nbr == 0)
		return;
	rec_kputunslong_base(nbr / base_n, base, count);
	*count += kputchar(base[nbr % base_n]);
}

int	kputunslong_base(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return kputchar(base[0]);
	rec_kputunslong_base(nbr, base, &count);
	return count;
}
