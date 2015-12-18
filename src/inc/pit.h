/*
** pit.h for yolok in /home/chauvo_t/Programming/Work_in_progress/Kernel/kfs/yolok
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Dec 17 23:24:22 2015 chauvo_t
** Last update Fri Dec 18 13:25:16 2015 chauvo_t
*/

#ifndef PIT_H_
# define PIT_H_

# include "types.h"

# define PIT_COUNTER_0		0x40
# define PIT_COUNTER_1		0x41
# define PIT_COUNTER_2		0x42
# define PIT_CONTROL		0x43
# define INPUT_CLOCK_FREQUENCY	1193182	// Input clock frequency (Hz)

typedef union
{
	uint8_t		val;
	struct pit_control_register
	{
		uint8_t	bcd	: 1;	// 0 = Binary counter 16 bits
					// 1 = Binary Coded Decimal counter (4 decades)
		uint8_t	mode	: 3;	// Mode. 0 to 5.
		uint8_t	rw	: 2;	// Read-Write
		uint8_t	sc	: 2;	// Select Counter. 0, 1, 2 = counter0,1,2.
					// 3 = Read-Back Command
	}		reg;
} pit_control_register_t;

void	pit_init(int freq);
int	pit_get_ticks(void);

#endif /* !PIT_H_ */
