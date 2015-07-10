/*
** strlen.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 20:53:43 2015 chauvo_t
** Last update Tue Jul  7 21:31:54 2015 chauvo_t
*/

int	strlen(char *str)
{
	register int	len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return len;
}
