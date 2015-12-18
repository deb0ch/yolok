/*
** irq.c for yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Dec 17 19:28:28 2015 chauvo_t
** Last update Fri Dec 18 12:45:04 2015 chauvo_t
*/

#include "asm_utils.h"
#include "interrupts.h"
#include "irq.h"

void	irq_init()
{
	pic_remap(0x20, 0x28);
	irq_mask_all();
	interrupts_set_isr(32, &isr32, ISR_KERNEL);
	interrupts_set_isr(33, &isr33, ISR_KERNEL);
	interrupts_set_isr(34, &isr34, ISR_KERNEL);
	interrupts_set_isr(35, &isr35, ISR_KERNEL);
	interrupts_set_isr(36, &isr36, ISR_KERNEL);
	interrupts_set_isr(37, &isr37, ISR_KERNEL);
	interrupts_set_isr(38, &isr38, ISR_KERNEL);
	interrupts_set_isr(39, &isr39, ISR_KERNEL);
	interrupts_set_isr(40, &isr40, ISR_KERNEL);
	interrupts_set_isr(41, &isr41, ISR_KERNEL);
	interrupts_set_isr(42, &isr42, ISR_KERNEL);
	interrupts_set_isr(43, &isr43, ISR_KERNEL);
	interrupts_set_isr(44, &isr44, ISR_KERNEL);
	interrupts_set_isr(45, &isr45, ISR_KERNEL);
	interrupts_set_isr(46, &isr46, ISR_KERNEL);
	interrupts_set_isr(47, &isr47, ISR_KERNEL);
}

void	irq_mask_all()
{
	outb(PIC1_DATA, 0xFF);
	outb(PIC2_DATA, 0xFF);
}

void	irq_unmask_all()
{
	outb(PIC1_DATA, 0x00);
	outb(PIC2_DATA, 0x00);
}

void	irq_set_mask(unsigned char irq_line)
{
	uint16_t port;
	uint8_t value;

	if (irq_line < 8)
		port = PIC1_DATA;
	else
	{
		port = PIC2_DATA;
		irq_line -= 8;
	}
	value = inb(port) | (1 << irq_line);
	outb(port, value);
}

void	irq_clear_mask(unsigned char irq_line)
{
	uint16_t port;
	uint8_t value;

	if (irq_line < 8)
		port = PIC1_DATA;
	else
	{
		port = PIC2_DATA;
		irq_line -= 8;
	}
	value = inb(port) & ~(1 << irq_line);
	outb(port, value);
}

/*
  arguments:
  offset1 - vector offset for master PIC
  vectors on the master become offset1..offset1 + 7
  offset2 - same for slave PIC: offset2..offset2 + 7
  on x86 it should be offset1 = 0x20 (32), offset2 = 0x28 (40)
  from http://wiki.osdev.org/8259_PIC#Programming_with_the_8259_PIC
*/
void	pic_remap(int offset1, int offset2)
{
	unsigned char a1;
	unsigned char a2;

	a1 = inb(PIC1_DATA);	// save masks
	a2 = inb(PIC2_DATA);

	outb(PIC1_COMMAND, ICW1_INIT + ICW1_ICW4);	// starts initialization in cascade mode
	cpu_relax();
	outb(PIC2_COMMAND, ICW1_INIT + ICW1_ICW4);
	cpu_relax();

	outb(PIC1_DATA, offset1);	// ICW2: master PIC vector offset
	cpu_relax();
	outb(PIC2_DATA, offset2);	// ICW2: slave PIC vector offset
	cpu_relax();

	outb(PIC1_DATA, 0x04);	// ICW3: tell master PIC that slave PIC is at IRQ2 (0000 0100)
	cpu_relax();
	outb(PIC2_DATA, 0x02);	// ICW3: tell slave PIC its cascade identity (0000 0010)
	cpu_relax();

	outb(PIC1_DATA, ICW4_8086);
	cpu_relax();
	outb(PIC2_DATA, ICW4_8086);
	cpu_relax();

	outb(PIC1_DATA, a1);   // restore saved masks.
	outb(PIC2_DATA, a2);
	cpu_relax();
}

void	pic_send_eoi(unsigned char irq)
{
	outb(PIC1_COMMAND, PIC_EOI);
	if (irq >= 32 + 8)
		outb(PIC2_COMMAND, PIC_EOI);
}
