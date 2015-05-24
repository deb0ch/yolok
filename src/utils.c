/*
** utils.c for yolo_k in /home/chauvo_t/Programming/Work_in_progress/Kernel/linux/linux_kernel
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 20:56:54 2015 chauvo_t
** Last update Sun May 24 20:57:30 2015 chauvo_t
*/

#include "utils.h"

void	my_memset(char *b, unsigned long v, unsigned long n)
{
  register unsigned long i;

  for (i = 0; i < n; ++i)
    b[i] = v;
}
