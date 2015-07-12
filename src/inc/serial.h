/*
** serial.h for yolo_k in /home/chauvo_t/Programming/Work_in_progress/Kernel/linux/linux_kernel
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 19:48:29 2015 chauvo_t
** Last update Thu Jun 25 20:40:46 2015 chauvo_t
*/

#ifndef SERIAL_H_
# define SERIAL_H_

# include "types.h"

# define BAUDRATE(x)	(115200 / x)

# define COM1  		0x3f8
# define COM2	       	0x2f8
# define COM3	       	0x3e8
# define COM4	       	0x2e8

# define THR	       	0	// ! Transmit Holding Register (Write)
# define RDR	       	0	// ! Receive Holding Register (Read)
# define DLL	       	0	// Divisor Latch low byte
# define DLM	       	1	// Divisor Latch high byte
# define IER	       	1	// ! Interrupt Enable Register
# define FCR	       	2	// ! Fifo Control Register (Write)
# define ISR	       	2	// Interrupt Status Register (Read)
# define LCR	       	3	// Line Control Register
# define MCR	       	4	// Modem Control Register
# define LSR	       	5	// Line Status Register
# define MSR	       	6	// Modem Status Register
# define SPR	       	7	// ScratchPad Register

# define LCR_BITS_5	0x00	// 5 bits/char
# define LCR_BITS_6	0x01	// 6 bits/char
# define LCR_BITS_7	0x02	// 7 bits/char
# define LCR_BITS_8	0x03	// 8 bits/char

struct	lcr_register
{
	uint8_t		word_len	: 2;
	uint8_t		stop		: 1;
	uint8_t		set_parity	: 1;
	uint8_t		even_parity	: 1;
	uint8_t		stick_parity	: 1;
	uint8_t		set_tx_break	: 1;
	uint8_t		dlab		: 1;
} __attribute__((packed));

typedef union
{
	struct lcr_register	reg;
	uint8_t			byte;
}		lcr_register_t;

struct	lsr_register
{
	uint8_t		data_available		: 1;
	uint8_t		overrun_error		: 1;
	uint8_t		parity_error		: 1;
	uint8_t		framing_error		: 1;
	uint8_t		brk_sig_received	: 1;
	uint8_t		thr_empty		: 1;
	uint8_t		thr_empty_idle		: 1;
	uint8_t		err_fifo		: 1;
} __attribute__((packed));

typedef union
{
	struct lsr_register	reg;
	uint8_t			byte;
}		lsr_register_t;

void	init_serial_port(int port);

#endif /* !SERIAL_H_ */
