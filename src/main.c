/*
** main.c for yolokernel in kfs-chauvo_t/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Fri May 22 18:33:17 2015 chauvo_t
** Last update Thu May 28 12:36:23 2015 chauvo_t
*/

#include "serial.h"
#include "utils.h"

/*
 * Framebuffer
 */
#define FRAMEBUFFER	(char*)0xb8000

#define BLACK		0
#define DARK_BLUE	1
#define GREEN		2
#define LIGHT_BLUE	3
#define RED		4
#define PURPLE		5
#define ORANGE		6
#define GREY		7

struct s_vga_text_char
{
  short ascii_code		: 8;
  short fg_color_rgb		: 3;
  short fg_color_intensity	: 1;
  short bg_color_rgb		: 3;
  short bg_color_intensity	: 1;
} __attribute__((packed));

typedef union	u_vga_text_char
{
  struct s_vga_text_char vga;
  char			 byte;
}		t_vga_text_char;

/*
 * @Todo: initialize other registers.
 */
void	init_serial_port(int port)
{
  t_lcr_register	lcr;

  lcr.byte = inb(port + 3);			// Get LCR register
  lcr.reg.dlab = 1;				// Write DLAB to access DLL and DLM registers
  outb(port + LCR, lcr.byte);			// Write LCR
  outb(port + DLM, HIGH8(BAUDRATE(38400)));	// Zero DLM
  outb(port + DLL, LOW8(BAUDRATE(38400)));	// Baudrate is 115200 / DLM:DLL
  lcr.reg.word_len = LCR_BITS_8;
  lcr.reg.stop = 0;				// 1 stop bit
  lcr.reg.set_parity = 0;			// No parity check
  lcr.reg.dlab = 0;
  outb(port + LCR, lcr.byte);			// Write LCR
}

void	init()
{
  my_memset(FRAMEBUFFER, 0, 80 * 25 * 2);
  init_serial_port(COM1);
}

void	printk_framebuffer(const char *msg)
{
  t_vga_text_char	c;
  int			i;

  c.vga.fg_color_rgb = 7;
  c.vga.fg_color_intensity = 0;
  c.vga.bg_color_rgb = 0;
  c.vga.bg_color_intensity = 0;
  i = 0;
  while (*msg)
    {
      c.vga.ascii_code = *msg;
      *((t_vga_text_char*)FRAMEBUFFER + i) = c;
      ++msg;
      ++i;
    }
}

/*
 * @Todo: write a send and a recv function, interrupt driven, to be less dirty.
 */
void	printk_serial(const char *msg)
{
  t_lsr_register	lsr;

  while (*msg)
    {
      lsr.byte = inb(COM1 + LSR);
      if (lsr.reg.thr_empty)
	{
	  outb(COM1 + THR, *msg);
	  ++msg;
	}
    }
}

void	printk(const char *msg)
{
  printk_framebuffer(msg);
  printk_serial(msg);
}

void    yolomain()
{
  init();
  while (1)
    {
      printk("Yolooo ! ");
    }
}
