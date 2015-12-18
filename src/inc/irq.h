/*
** irq.h for yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Dec 17 19:22:45 2015 chauvo_t
** Last update Thu Dec 17 21:30:27 2015 chauvo_t
*/

#ifndef IRQ_H_
# define IRQ_H_

# define PIC1			0x20		// IO base address for master PIC
# define PIC2			0xA0		// IO base address for slave PIC

# define PIC1_COMMAND		(PIC1 + 0)
# define PIC1_DATA		(PIC1 + 1)

# define PIC2_COMMAND		(PIC2 + 0)
# define PIC2_DATA		(PIC2 + 1)

# define ICW1_INIT		0x10		// Initialization command
# define ICW1_ICW4		0x01		// ICW4 (not) needed
# define ICW1_SINGLE		0x02		// Single mode (no cascade)
# define ICW1_INTERVAL4		0x04		// Call address interval 4 (8)
# define ICW1_LEVEL		0x08		// Level triggered mode (no edge)

# define ICW4_8086		0x01		// 8086/88 (MCS-80/85) mode
# define ICW4_AUTO		0x02		// Auto (normal) EOI
# define ICW4_BUF_SLAVE		0x08		// Buffered mode/slave
# define ICW4_BUF_MASTER	0x0C		// Buffered mode/master
# define ICW4_SFNM		0x10		// Special fully nested (not)

# define PIC_EOI		0x20		// End-of-interrupt command code

void	irq_init();
void	pic_remap(int offset1, int offset2);
void	irq_mask_all();
void	irq_unmask_all();
void	irq_set_mask(unsigned char irq_line);
void	irq_clear_mask(unsigned char irq_line);
void	pic_remap(int offset1, int offset2);
void	pic_send_eoi(unsigned char irq);

#endif /* !IRQ_H_ */
