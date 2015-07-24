/*
** framebuffer.h for yolok in yolok/src
**
** Made by chauvo_t
** Login   <chauvo_t@epitech.net>
**
** Started on  Thu Jun 25 15:28:07 2015 chauvo_t
** Last update Fri Jul 24 13:55:16 2015 deb0ch
*/

#ifndef VGA_H_
# define VGA_H_

# define VGA_BASE		(char*)0xb8000

# define VGA_WIDTH		(int)80
# define VGA_HEIGHT		(int)25

# define VGA_COORD(x, y)	(int)((x) + (y) * VGA_WIDTH)
# define VGA_ROW(c)		(int)((c) / VGA_WIDTH)
# define VGA_COL(c)		(int)((c) % VGA_WIDTH)

# define VGA_BLACK		0
# define VGA_BLUE		1
# define VGA_GREEN		2
# define VGA_CYAN		3
# define VGA_RED		4
# define VGA_MAGENTA		5
# define VGA_BROWN		6
# define VGA_LIGHT_GREY		7
# define VGA_DARK_GREY		8
# define VGA_LIGHT_BLUE		9
# define VGA_LIGHT_GREEN	10
# define VGA_LIGHT_CYAN		11
# define VGA_LIGHT_RED		12
# define VGA_LIGHT_MAGENTA	13
# define VGA_LIGHT_BROWN	14
# define VGA_WHITE		15

struct s_vga_text_char
{
	uint8_t ascii;
	union
	{
		uint8_t byte;
		struct
		{
			uint8_t fg_color_rgb		: 3;
			uint8_t fg_color_intensity	: 1;
			uint8_t bg_color_rgb		: 3;
			uint8_t bg_color_intensity	: 1;
		};
	} color;
} __attribute__((packed));

typedef union	u_vga_text_char
{
	struct s_vga_text_char	vga;
	uint16_t		raw;
}		vga_text_char_t;

#endif /* !VGA_H_ */
