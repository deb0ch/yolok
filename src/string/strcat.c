/*
** strcat.c for yolok in yolok/src/printk/printf/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Tue Jul  7 20:56:50 2015 chauvo_t
** Last update Tue Jul  7 21:32:04 2015 chauvo_t
*/

#include "string.h"

/*
 * dest has to have a sufficiently large allocated memory
 * space to take src.
 */
char	*strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + dest_len] = src[i];
		i += 1;
	}
	dest[i + dest_len] = '\0';
	return dest;
}
