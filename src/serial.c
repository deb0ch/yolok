/*
** serial.c for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 15:25:54 2015 chauvo_t
** Last update Thu Nov 26 20:47:41 2015 chauvo_t
*/

#include "serial.h"
#include "asm_utils.h"

/*
 * @Todo: initialize other registers.
 */
void	init_serial_port(int port)
{
	lcr_register_t	lcr;

	lcr.byte = inb(port + 3);			// Get LCR register
	lcr.reg.dlab = 1;				// Write DLAB to access DLL and DLM
							// registers
	outb(port + LCR, lcr.byte);			// Write LCR
	outb(port + DLM, HIGH8(BAUDRATE(38400)));	// Zero DLM
	outb(port + DLL, LOW8(BAUDRATE(38400)));	// Baudrate is 115200 / DLM:DLL
	lcr.reg.word_len = LCR_BITS_8;
	lcr.reg.stop = 0;				// 1 stop bit
	lcr.reg.set_parity = 0;				// No parity check
	lcr.reg.dlab = 0;
	outb(port + LCR, lcr.byte);			// Write LCR
}
