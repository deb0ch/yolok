/*
** stdio.h for yolok in yolok/src/string
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:49:58 2015 chauvo_t
** Last update Tue Jul  7 21:53:48 2015 chauvo_t
*/

#ifndef STDIO_H_
# define STDIO_H_

int	printf(char *format, ...);
int	putchar(char c);
int	putnbr(int nb);
int	putnbr_base(int nbr, char *base);
int	putstr(char *str);
int	putunslong_base(unsigned long nbr, char *base);
int	putunsint_base(unsigned int nbr, char *base);
void	show_wordtab(char **tab);

#endif /* !STDIO_H_ */
