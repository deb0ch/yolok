/*
** interrupts.h for yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri Nov 20 11:29:57 2015 chauvo_t
** Last update Fri Dec 18 01:02:22 2015 chauvo_t
*/

#ifndef INTERRUPTS_H_
# define INTERRUPTS_H_

#include "types.h"

# define ISR_KERNEL	0
# define ISR_USER	1

# define IDT_SIZE	256

/*
 * Intel manual Vol. 3A 6-10 (pdf p2105) - Figure 6-1
 */
struct idtr_register
{
	uint16_t	limit;
	uint32_t	base_address;
} __attribute__((packed));

/*
 * Intel manual Vol. 3A 6-11 (pdf p2106) - Figure 6-2:
 * for trap and interrupt gates, the 3 highest bytes of
 * reserved1 must be set to 0.
 * reserved2 must always be 0.
 * gate_type:	0b101: task gate
 *		0b110: interrupt gate
 *		0b111: trap gate
 * size_of_gate: 1 = 32 bits, 0 = 16 bits
 */
struct idt_gate_descriptor
{
	uint32_t	handler_addr_low		: 16;
	uint32_t	segment_selector		: 16;
	uint32_t	reserved1			: 8;
	uint32_t	gate_type			: 3;
	uint32_t	size_of_gate			: 1;
	uint32_t	reserved2			: 1;
	uint32_t	descriptor_privilege_level	: 2;
	uint32_t	segment_present			: 1;
	uint32_t	handler_addr_high		: 16;
} __attribute__((packed));

/*
 * Intel manual Vol. 3A 6-15 (pdf p2110):
 */
struct isr_general_errcode
{
	uint32_t	ext			: 1;	// External event (bit 0)
	uint32_t	idt			: 1;	// Descriptor location (bit 1)
	uint32_t	ti			: 1;	// GDT/LDT (bit 2)
	uint32_t	segment_selector_index	: 13;	// index in gdt
	uint32_t	reserved		: 16;
} __attribute__((packed));

/*
 * Intel manual Vol. 3A 6-41 (pdf p2136) - Figure 6-9:
 */
struct isr_page_fault_errcode
{
	uint32_t	p	: 1;	// P	0 The fault was caused by a non-present page.
					//	1 The fault was caused by a page-level
					//	protection violation.
	uint32_t	w_r	: 1;	// W/R	0 The access causing the fault was a read.
					//	1 The access causing the fault was a write.
	uint32_t	u_s	: 1;	// U/S	0 A supervisor-mode access caused the fault.
					//	1 A user-mode access caused the fault.
	uint32_t	rsvd	: 1;	// RSVD	0 The fault was not caused by reserved bit
					//	violation.
					//	1 The fault was caused by a reserved bit set
					//	to 1 in some paging-structure entry.
	uint32_t	i_d	: 1;	// I/D	0 The fault was not caused by an instruction fetch.
					//	1 The fault was caused by an instruction fetch.
	uint32_t	pk	: 1;	// PK	0 The fault was not caused by protection keys.
					//	1 There was a protection-key violation.
	uint32_t	reserved: 26;
} __attribute__((packed));

union isr_errcode
{
	uint32_t			value;
	struct isr_general_errcode	general;
	struct isr_page_fault_errcode	pagefault;
};

struct isr_context
{
	uint32_t		ds;	// Why not save that
	uint32_t		es;
	uint32_t		fs;
	uint32_t		gs;

	uint32_t		edi;	// Registers pushed by pusha instruction, in order
	uint32_t		esi;
	uint32_t		ebp;
	uint32_t		esp;
	uint32_t		ebx;
	uint32_t		edx;
	uint32_t		ecx;
	uint32_t		eax;

	uint32_t		interrupt_id;

	union isr_errcode	error_code;

	uint32_t		eip;	// Pushed by int instruction
	uint32_t		cs;
	uint32_t		eflags;
	uint32_t		esp_;
	uint32_t		ss;
};

typedef int (*isr_handler_t)(struct isr_context* regs);

void	interrupts_init();

/*
  n: interrupt index
  handler: pointer to the IRQ handler
  flags:
  ISR_USER: the user can call it
  ISR_KERNEL: can only be called from kernel land
*/
void	interrupts_set_isr(int n, isr_handler_t handler, int flags);

void	load_idt(struct idtr_register *idtr);

/*
 * General interrupts handler, called from asm file
 * on all software and hardware interrupts
 */
int	interrupts_handler(struct isr_context *context);

int	isr_dummy_handler(struct isr_context *context);

extern int isr0(struct isr_context *);
extern int isr1(struct isr_context *);
extern int isr2(struct isr_context *);
extern int isr3(struct isr_context *);
extern int isr4(struct isr_context *);
extern int isr5(struct isr_context *);
extern int isr6(struct isr_context *);
extern int isr7(struct isr_context *);
extern int isr8(struct isr_context *);
extern int isr9(struct isr_context *);
extern int isr10(struct isr_context *);
extern int isr11(struct isr_context *);
extern int isr12(struct isr_context *);
extern int isr13(struct isr_context *);
extern int isr14(struct isr_context *);
extern int isr15(struct isr_context *);
extern int isr16(struct isr_context *);
extern int isr17(struct isr_context *);
extern int isr18(struct isr_context *);
extern int isr19(struct isr_context *);
extern int isr20(struct isr_context *);
extern int isr21(struct isr_context *);
extern int isr22(struct isr_context *);
extern int isr23(struct isr_context *);
extern int isr24(struct isr_context *);
extern int isr25(struct isr_context *);
extern int isr26(struct isr_context *);
extern int isr27(struct isr_context *);
extern int isr28(struct isr_context *);
extern int isr29(struct isr_context *);
extern int isr30(struct isr_context *);
extern int isr31(struct isr_context *);

extern int isr32(struct isr_context *);
extern int isr33(struct isr_context *);
extern int isr34(struct isr_context *);
extern int isr35(struct isr_context *);
extern int isr36(struct isr_context *);
extern int isr37(struct isr_context *);
extern int isr38(struct isr_context *);
extern int isr39(struct isr_context *);
extern int isr40(struct isr_context *);
extern int isr41(struct isr_context *);
extern int isr42(struct isr_context *);
extern int isr43(struct isr_context *);
extern int isr44(struct isr_context *);
extern int isr45(struct isr_context *);
extern int isr46(struct isr_context *);
extern int isr47(struct isr_context *);

#endif /* !INTERRUPTS_H_ */
