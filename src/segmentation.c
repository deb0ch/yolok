/*
** segmentation.c for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 16:00:42 2015 chauvo_t
** Last update Sun Jul 12 12:56:53 2015 chauvo_t
*/

#include "segmentation.h"
#include "string.h"
#include "utils.h"

gdt_entry_t		gdt[GDT_SIZE];
struct gdt_register	gdtr;

/*
 * @Description: Set a GDT entry.
 * @Arguments:
 *	n: entry index
 *	base: segment base address
 *	limit: segment limit
 *	access: segment access attributes
 *	granularity: segment limit granularity
 */
int	set_gdt_entry(int n, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
{
	(void)n;
	(void) base;
	(void) limit;
	(void) access;
	(void) granularity;
	((gdt_entry_t*)base)->s = 1;
	return 0;
}

void	init_flat_gdt(void)
{
	uint8_t	access = 0;

	(void)access;
	gdtr.limit = GDT_SIZE * sizeof(gdt_entry_t);
	gdtr.base = (typeof(gdtr.base))&gdt;
	memset(&gdt, 0, sizeof(gdt));
}
