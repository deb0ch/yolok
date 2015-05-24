/*
** serial.h for yolo_k in /home/chauvo_t/Programming/Work_in_progress/Kernel/linux/linux_kernel
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Sun May 24 19:48:29 2015 chauvo_t
** Last update Sun May 24 20:50:38 2015 chauvo_t
*/

#ifndef SERIAL_H_
# define SERIAL_H_

/* typedefs that the insideout headers need */
# ifndef LOW8
#  define LOW8(a)	((unsigned char)(a & 0xff))
# endif

# ifndef HIGH8
#  define HIGH8(a)	((unsigned char)((a & 0xff00) >> 8))
# endif

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

struct	s_lcr_register
{
  char		word_len	: 2;
  char		stop		: 1;
  char		set_parity	: 1;
  char		even_parity	: 1;
  char		stick_parity	: 1;
  char		set_tx_break	: 1;
  char		dlab		: 1;
} __attribute__((packed));

typedef union	u_lcr_register
{
  struct s_lcr_register reg;
  char			byte;
}		t_lcr_register;

struct	s_lsr_register
{
  char		data_available	: 1;
  char		overrun_error	: 1;
  char		parity_error	: 1;
  char		framing_error	: 1;
  char		brk_sig_received: 1;
  char		thr_empty	: 1;
  char		thr_empty_idle	: 1;
  char		err_fifo	: 1;
} __attribute__((packed));

typedef union	u_lsr_register
{
  struct s_lsr_register reg;
  char			byte;
}		t_lsr_register;

#endif /* !SERIAL_H_ */
