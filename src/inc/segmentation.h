/*
** segmentation.h for yolok yolok/include
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 16:00:18 2015 chauvo_t
** Last update Sun Jul 19 20:23:26 2015 deb0ch
*/

#ifndef SEGMENTATION_H_
# define SEGMENTATION_H_

# include "types.h"

# define GDT_SIZE 3
# define MAX_MEM_SIZE (unsigned int)-1;

# define SEGMENTS_BASE		0
# define SEGMENTS_SIZE		0xFFFFFFFF
# define GDT_ENTRIES		16

# define RING_LVL_0		0 << 5
# define RING_LVL_1		1 << 5
# define RING_LVL_2		2 << 5
# define RING_LVL_3		3 << 5

# define SEG_PRESENT		1 << 7
# define SEG_NOT_PRESENT	0 << 7

# define DTYPE_S_SYS		0 << 4
# define DTYPE_S_CODE		1 << 4

# define TYPE_DATA_RO		0
# define TYPE_DATA_RW		2
# define TYPE_DATA_RO_ED	4
# define TYPE_DATA_RW_ED	6
# define TYPE_CODE_EO		8
# define TYPE_CODE_ER		10
# define TYPE_CODE_EO_C		12
# define TYPE_CODE_ER_C		14

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

void	set_gdt_entry(uint32_t index,
		      uint32_t base,
		      uint32_t limit,
		      uint8_t access,
		      uint8_t granularity);
void	init_flat_gdt(void);

#endif /* !SEGMENTATION_H_ */
