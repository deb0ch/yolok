/*
** segmentation.h for yolok yolok/include
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 16:00:18 2015 chauvo_t
** Last update Tue Jul  7 19:17:29 2015 chauvo_t
*/

#ifndef SEGMENTATION_H_
# define SEGMENTATION_H_

# include "types.h"

# define GDT_SIZE 3
# define MAX_MEM_SIZE (unsigned int)-1;

/*
 * Cf. Intel Manual Vol. 3A 3-9 (2007)
 */
union gdt_entry
{
	struct
	{
		uint32_t	raw0;
		uint32_t	raw1;
	};
	struct
	{
		uint32_t	limit_low	: 16; /* Segment Limit */
		uint32_t	base_low	: 16; /* Segment base address */
		uint32_t	base_mid	: 8;  /* Segment base address */
		uint32_t	type		: 4;  /* Segment type */
		uint32_t	s		: 1;  /* Descriptor type (0 = system;
							 1 = code or data) */
		uint32_t	dpl		: 2;  /* Descriptor privilege level */
		uint32_t	p		: 1;  /* Segment present */
		uint32_t	limit_high	: 4;  /* Segment Limit */
		uint32_t	avl		: 1;  /* Available for use by system software */
		uint32_t	l		: 1;  /* 64-bit code segment (IA-32e mode only) */
		uint32_t	d_b		: 1;  /* Default operation size (0 = 16-bit
							 segment; 1 = 32-bit segment) */
		uint32_t	g		: 1;  /* Granularity */
		uint32_t	base_high	: 8;  /* Segment base address */
	};
};

typedef union gdt_entry	gdt_entry_t;

struct gdt_register
{
	uint16_t	limit;
	uint32_t	base;
};

int	set_gdt_entry(int n, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);
void	init_flat_gdt(void);

#endif /* !SEGMENTATION_H_ */
