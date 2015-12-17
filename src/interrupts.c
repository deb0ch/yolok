/*
** interrupts.c for yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri Nov 20 11:30:53 2015 chauvo_t
** Last update Thu Dec 17 22:17:08 2015 chauvo_t
*/

#include "asm_utils.h"
#include "irq.h"
#include "interrupts.h"
#include "kstdio.h"
#include "string.h"

struct idtr_register		g_idtr_register;
struct idt_gate_descriptor	g_idt_gate_descritors[IDT_SIZE];
isr_handler_t			g_interrupt_handlers[IDT_SIZE];

void	interrupts_init()
{
	g_idtr_register.limit = (sizeof(struct idt_gate_descriptor) * IDT_SIZE) - 1;
	g_idtr_register.base_address = (uint32_t)&g_idt_gate_descritors;
	(void)memset(&g_idt_gate_descritors,
		     0,
		     sizeof(struct idt_gate_descriptor) * IDT_SIZE);
	for (int i = 0; i < IDT_SIZE; ++i)
	{
		g_interrupt_handlers[i] = &isr_dummy_handler;
	}
	g_interrupt_handlers[33] = isr_keyboard_handler; // handle keyboard inputs
	interrupts_set_isr(0, &isr0, ISR_KERNEL);
	interrupts_set_isr(1, &isr1, ISR_KERNEL);
	interrupts_set_isr(2, &isr2, ISR_KERNEL);
	interrupts_set_isr(3, &isr3, ISR_KERNEL);
	interrupts_set_isr(4, &isr4, ISR_KERNEL);
	interrupts_set_isr(5, &isr5, ISR_KERNEL);
	interrupts_set_isr(6, &isr6, ISR_KERNEL);
	interrupts_set_isr(7, &isr7, ISR_KERNEL);
	interrupts_set_isr(8, &isr8, ISR_KERNEL);
	interrupts_set_isr(9, &isr9, ISR_KERNEL);
	interrupts_set_isr(10, &isr10, ISR_KERNEL);
	interrupts_set_isr(11, &isr11, ISR_KERNEL);
	interrupts_set_isr(12, &isr12, ISR_KERNEL);
	interrupts_set_isr(13, &isr13, ISR_KERNEL);
	interrupts_set_isr(14, &isr14, ISR_KERNEL);
	interrupts_set_isr(15, &isr15, ISR_KERNEL);
	interrupts_set_isr(16, &isr16, ISR_KERNEL);
	interrupts_set_isr(17, &isr17, ISR_KERNEL);
	interrupts_set_isr(18, &isr18, ISR_KERNEL);
	interrupts_set_isr(19, &isr19, ISR_KERNEL);
	interrupts_set_isr(20, &isr20, ISR_KERNEL);
	interrupts_set_isr(21, &isr21, ISR_KERNEL);
	interrupts_set_isr(22, &isr22, ISR_KERNEL);
	interrupts_set_isr(23, &isr23, ISR_KERNEL);
	interrupts_set_isr(24, &isr24, ISR_KERNEL);
	interrupts_set_isr(25, &isr25, ISR_KERNEL);
	interrupts_set_isr(26, &isr26, ISR_KERNEL);
	interrupts_set_isr(27, &isr27, ISR_KERNEL);
	interrupts_set_isr(28, &isr28, ISR_KERNEL);
	interrupts_set_isr(29, &isr29, ISR_KERNEL);
	interrupts_set_isr(30, &isr30, ISR_KERNEL);
	interrupts_set_isr(31, &isr31, ISR_KERNEL);
	load_idt(&g_idtr_register);
	irq_init();
	enable_interrupt();
}

/*
 * Two flags are accepted: ISR_KERNEL or ISR_USER, depending on if
 * the interrupt was triggered from kernel land or user land.
 */
void	interrupts_set_isr(int n, isr_handler_t handler, int flags)
{
	g_idt_gate_descritors[n].handler_addr_low = (uint32_t)handler & 0xFFFF;
	g_idt_gate_descritors[n].segment_selector = 0x08;	// offset in bytes in GDT
	g_idt_gate_descritors[n].reserved1 = 0x00;
	g_idt_gate_descritors[n].gate_type = 0x06;		// 0b110
	g_idt_gate_descritors[n].size_of_gate = 0x01;
	g_idt_gate_descritors[n].reserved2 = 0x00;
	g_idt_gate_descritors[n].descriptor_privilege_level = flags == ISR_KERNEL ? 0x00 : 0x03;
	g_idt_gate_descritors[n].segment_present = 1;
	g_idt_gate_descritors[n].handler_addr_high = ((uint32_t)handler >> 16) & 0xFFFF;
}

void load_idt(struct idtr_register *idtr)
{
	asm volatile("lidt %0\n"
		     :
		     : "m" (*idtr)
		     : "memory");
}

int	interrupts_handler(struct isr_context *context)
{
	int ret;

	if (g_interrupt_handlers[context->interrupt_id])
	{
		ret = g_interrupt_handlers[context->interrupt_id](context);
		if (context->interrupt_id > 31)
			pic_send_eoi(context->interrupt_id);
		return ret;
	}
	return -1;
}

void	isr_print_errcode(union isr_errcode errcode)
{
	kprintf("general errcode:\next = %X\n", errcode.general.ext);
	kprintf("idt = %X\n", errcode.general.idt);
	kprintf("ti = %X\n", errcode.general.ti);
	kprintf("index = %X\n", errcode.general.segment_selector_index);
	kprintf("\n");
	kprintf("pagefault errcode: p = %X\n", errcode.pagefault.p);
	kprintf("w_r = %X\n", errcode.pagefault.w_r);
	kprintf("u_s = %X\n", errcode.pagefault.u_s);
	kprintf("rsvd = %X\n", errcode.pagefault.rsvd);
	kprintf("i_d = %X\n", errcode.pagefault.i_d);
	kprintf("pk = %X\n", errcode.pagefault.pk);
}

int	isr_keyboard_handler(struct isr_context *context)
{
	uint8_t keycode;

	(void)context;
	keycode = inb(KEYBOARD_IO_PORT);
	kprintf("%c ", keycode);
	return keycode;
}

int	isr_dummy_handler(struct isr_context *context)
{
	static int	i = 0;

	if (i < 8)
	{
		kprintf("interrupt called: %d", context->interrupt_id);
		kprintf(" (%d)", i++);
		kprintf("\n");
		if (context->error_code.value != 0xdead0000)
		{
			kprintf("error = %x\n", context->error_code);
			isr_print_errcode(context->error_code);
		}
	}
	return 0;
}
