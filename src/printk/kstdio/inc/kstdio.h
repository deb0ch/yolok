/*
** kstdio.h for yolok in yolok/src/printk/kstdio
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 21:49:58 2015 chauvo_t
** Last update Sun Jul 12 16:00:05 2015 chauvo_t
*/

#ifndef KSTDIO_H_
# define KSTDIO_H_

int	kprintf(char *format, ...);
int	kputchar(char c);
int	kputnbr(int nb);
int	kputnbr_base(int nbr, char *base);
int	kputstr(char *str);
int	kputunslong_base(unsigned long nbr, char *base);
int	kputunsint_base(unsigned int nbr, char *base);
void	kshow_wordtab(char **tab);

#endif /* !KSTDIO_H_ */
