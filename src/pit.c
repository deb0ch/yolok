/*
** pit.c for yolok in /home/chauvo_t/Programming/Work_in_progress/Kernel/kfs/yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Dec 17 23:24:29 2015 chauvo_t
** Last update Fri Dec 18 21:21:18 2015 chauvo_t
*/

#include "asm_utils.h"
#include "interrupts.h"
#include "irq.h"
#include "pit.h"

#include "kstdio.h"
#include "kwrite.h"

extern isr_handler_t	g_interrupt_handlers[IDT_SIZE];
static int		g_ticks = 0;

int	isr_timer_handler(struct isr_context *context)
{
	(void)context;
	kwrite(KWRITE_SERIAL, "tick\n", 5);
	return g_ticks++;
}

/*
 * Init PIT with:
 * Counter 0
 * Mode 2
 * Interrupt rate : 100 Hz
 */
void pit_init(int freq)
{
	pit_control_register_t	reg;
	uint16_t		divisor;

	kprintf("freq = %d\n", freq);
	divisor = INPUT_CLOCK_FREQUENCY / (freq ? freq : 1);
	kprintf("divisor = %d\n", divisor);
	reg.reg.bcd = 0;
	reg.reg.mode = 2;
	reg.reg.rw = 3;
	reg.reg.sc = 0;
	kprintf("pit control register = 0x%X\n", reg.val);
	outb(PIT_CONTROL, (uint8_t)reg.val);
	outb(PIT_COUNTER_0, ((char *)&divisor)[0]);
	outb(PIT_COUNTER_0, ((char *)&divisor)[1]);
	g_interrupt_handlers[32] = isr_timer_handler;	// handle timer interrupts
	irq_clear_mask(0);				// PIT (Programmable Interval Timer)
}

int pit_get_ticks(void)
{
	return g_ticks;
}
