/*
** kputunsint_base.c for yolok in yolok/src/printk/kstdio
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 20:58:07 2015 chauvo_t
** Last update Sun Jul 12 17:00:36 2015 chauvo_t
*/

#include "kstdio.h"
#include "string.h"

static void	rec_kputunsint_base(unsigned int nbr, char *base, int *count)
{
	int	base_n;

	base_n = strlen(base);
	if (nbr == 0)
		return ;
	rec_kputunsint_base(nbr / base_n, base, count);
	*count += kputchar(base[nbr % base_n]);
}

int	kputunsint_base(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (kputchar(base[0]));
	rec_kputunsint_base(nbr, base, &count);
	return count;
}
