/*
** segmentation.c for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 16:00:42 2015 chauvo_t
** Last update Thu Dec 17 21:56:09 2015 chauvo_t
*/

#include "segmentation.h"
#include "string.h"
#include "asm_utils.h"

#include "kstdio.h"

struct gdt_entry	g_gdt[GDT_SIZE];
struct gdt_register	g_gdtr;

static inline void load_gdt(struct gdt_register *gdtr)
{
	asm volatile("lgdt %0 \n\t"
		     : /* no output */
		     : "m" (*gdtr)
		     : "memory");
	asm volatile("mov %cr0,%eax \n\t"
		     "or $1,%al     \n\t"
		     "mov %eax,%cr0 \n\t"); /* Why ? */
}

static inline void load_segments_selectors(void)
{
	/*
	 * Pos new Data Segment = base GDT + index Data sgement
	 * Pos Data descriptor = base GDT [ 2 ]
	 * Therefore, first part of each segment selector should be 2 (0b10)
	 * TI: Table Indicator. Says either gdt or ldt should be used.
	 * RPL: Ring Privilege Level.
	 * ldt is like gdt, but local to a process. Deprecated and not used in modern systems.
	 * TI = 0 for GDT selected, and RPL = 0 for Ring 0 Privilege
	 * Therefore Segment selector has to be set from ax like this:
	 * ax = 0b10 | TI | (RPL & 0b11) => (bin) 0b10 000 <=> (hex) 0x10
	 */
	asm volatile ("movw $0x10, %ax \n\t"
		      "movw %ax, %ds \n\t"
		      "movw %ax, %es \n\t"
		      "movw %ax, %fs \n\t"
		      "movw %ax, %gs \n\t"
		      "movw %ax, %ss \n\t");
	/* Code Segment Reloading: only CS needs reloading (Whaaaat ?!? This is WTF x86 yolo) */
	asm volatile ("pushl $0x08 \n\t" /* Far push to set CS to index 0x08 (after Null desc) */
		      "pushl $1f \n\t"   /* Far push to set EIP after ret. label 1 f(orward) */
		      "lret \n\t"	 /* lret: pop eip AND a new value for CS on the stack */
		      "1:");
}

/*
 * @Description: Set a GDT entry.
 * @Arguments:
 *	index: entry index
 *	base: segment base address
 *	limit: segment limit
 *	access: segment access attributes
 *	granularity: segment limit granularity
 */
void	set_gdt_entry(uint32_t index,
		      uint32_t base,
		      uint32_t limit,
		      uint8_t access,
		      uint8_t granularity)
{
	memset(&g_gdt[index], 0, sizeof(struct gdt_entry));
      	g_gdt[index].limit_low	 = limit & 0x0000FFFF;
	g_gdt[index].base_low	 = base & 0x0000FFFF;
	g_gdt[index].base_mid	 = (base >> 16) & 0xFF;
	g_gdt[index].type	 = access & 0x0F;
	g_gdt[index].s		 = (access & DTYPE_S_CODE) ? 1 : 0;
	g_gdt[index].dpl	 = (access & 0x60) >> 5;
	g_gdt[index].p		 = (access & SEG_PRESENT) ? 1 : 0;
	g_gdt[index].limit_high	 = (limit >> 16) & 0xFF;
	g_gdt[index].avl	 = 0x0;
	g_gdt[index].l		 = 0x0;
	g_gdt[index].d_b	 = 0x1;
	g_gdt[index].g		 = granularity;
	g_gdt[index].base_high	 = (base >> 24) & 0xFF;
}

/*
 * HOWTO switch to Protected Mode:
 * http://files.osdev.org/mirrors/geezer/os/pm.htm
 */
void	init_flat_gdt(void)
{
	uint8_t		access = 0;

	g_gdtr.limit = (GDT_SIZE * sizeof(struct gdt_entry)) - 1;
	g_gdtr.base = (uint32_t)&g_gdt;
	memset(&g_gdt, 0, sizeof(g_gdt) * GDT_SIZE);

	/* NULL Segment */
	access = RING_LVL_0 | SEG_NOT_PRESENT | DTYPE_S_CODE | TYPE_DATA_RO;
	set_gdt_entry(0, SEGMENTS_BASE, 0, access, 0x0);

	/* Code Segement */
	access = RING_LVL_0 | SEG_PRESENT | DTYPE_S_CODE | TYPE_CODE_ER;
	set_gdt_entry(1, SEGMENTS_BASE , SEGMENTS_SIZE, access, 0x1);

	/* Data Segment */
	access = RING_LVL_0 | SEG_PRESENT | DTYPE_S_CODE | TYPE_DATA_RW;
	set_gdt_entry(2, SEGMENTS_BASE, SEGMENTS_SIZE, access, 0x1);

	load_gdt(&g_gdtr);
	load_segments_selectors();
}
