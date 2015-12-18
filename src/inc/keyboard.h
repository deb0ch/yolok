/*
** keyboard.h for yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri Dec 18 00:51:52 2015 chauvo_t
** Last update Fri Dec 18 00:59:19 2015 chauvo_t
*/

#ifndef KEYBOARD_H_
# define KEYBOARD_H_

# define KEYBOARD_IO_PORT	0x60	// keyboard buffer I/O space address
# define KEYBOARD_STATUS_PORT	0x64	// keyboard status register I/O space address

void	keyboard_init();
int	isr_keyboard_handler(struct isr_context *context);

#endif /* !KEYBOARD_H_ */
