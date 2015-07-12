/*
** string.h for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:36:29 2015 chauvo_t
** Last update Fri Jul 10 17:46:21 2015 chauvo_t
*/

#ifndef STRING_H_
# define STRING_H_

# include "printf.h"

int	getnbr(char *str);
void	memset(void *b, unsigned long v, unsigned long n);
char*	strcat(char *dest, char *src);
int	strcmp(char *s1, char *s2);
char*	strcpy(char *dest, char *src);
int	strlen(char *str);
char**	str_to_wordtab(char *str, char *spacing_chars);

#endif /* !STRING_H_ */
