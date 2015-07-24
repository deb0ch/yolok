/*
** string.h for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:36:29 2015 chauvo_t
** Last update Thu Jul 23 16:16:24 2015 deb0ch
*/

#ifndef STRING_H_
# define STRING_H_

# include "types.h"

int	getnbr(char *str);
void*	memcpy(void *dest, const void *src, size_t n);
void*	memmove(void *dest, const void *src, size_t n);
void	memset(void *b, unsigned long v, unsigned long n);
char*	strcat(char *dest, char *src);
int	strcmp(char *s1, char *s2);
char*	strcpy(char *dest, char *src);
int	strlen(char *str);
char**	str_to_wordtab(char *str, char *spacing_chars);

#endif /* !STRING_H_ */
