/*
** keyboard.c for yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri Dec 18 00:52:06 2015 chauvo_t
** Last update Fri Dec 18 10:07:56 2015 chauvo_t
*/

#include "asm_utils.h"
#include "interrupts.h"
#include "irq.h"
#include "keyboard.h"
#include "kstdio.h"

extern isr_handler_t	g_interrupt_handlers[IDT_SIZE];

void	keyboard_init()
{
	g_interrupt_handlers[33] = isr_keyboard_handler;	// handle keyboard inputs
	irq_clear_mask(1);					// clear keyboard PIC irq mask
}

int	isr_keyboard_handler(struct isr_context *context)
{
	uint8_t keycode;

	(void)context;
	keycode = inb(KEYBOARD_IO_PORT);
	kprintf("%d ", keycode);
	return keycode;
}
