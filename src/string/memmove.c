/*
** memmove.c for yolok in yolok/src/string
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:48:05 2015 chauvo_t
** Last update Thu Jul 23 16:42:24 2015 deb0ch
*/

#include "types.h"

/*
 * To do: use a better memory allocation than this
 * To do: stack does not work
 */
void*	memmove(void* dest, const void* src, size_t n)
{
	register size_t i;
	char		buf[10 * 4096];

	for (i = 0; i < n; ++i)
		((char*)buf)[i] = ((char*)src)[i];
	for (i = 0; i < n; ++i)
		((char*)dest)[i] = ((char*)buf)[i];
	return dest;
}
