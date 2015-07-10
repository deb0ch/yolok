/*
** printk.h for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 15:37:47 2015 chauvo_t
** Last update Tue Jul  7 18:53:36 2015 chauvo_t
*/

#ifndef PRINTK_H_
# define PRINTK_H_

void	printk_vga(const char *msg);
void	printk_serial(const char *msg);
void	printk(const char *msg);

#endif /* !PRINTK_H_ */
