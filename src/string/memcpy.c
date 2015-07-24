/*
** memcpy.c for yolok in yolok/src/string
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:48:05 2015 chauvo_t
** Last update Thu Jul 23 16:03:29 2015 deb0ch
*/

#include "types.h"

void*	memcpy(void* dest, const void* src, size_t n)
{
	register size_t i;

	for (i = 0; i < n; ++i)
		((char*)dest)[i] = ((char*)src)[i];
	return dest;
}
