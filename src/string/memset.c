/*
** memset.c for yolok in yolok/src/string
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:48:05 2015 chauvo_t
** Last update Fri Jul 10 17:52:08 2015 chauvo_t
*/

void	memset(void *b, unsigned long v, unsigned long n)
{
	register unsigned long i;

	for (i = 0; i < n; ++i)
		((char*)b)[i] = v;
}
