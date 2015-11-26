/*
** kwrite_vga.c for yolok in yolok/src/kwrite
**
** Made by deb0ch
** Login   <chauvo_t@epitech.net>
**
** Started on  Wed Jul 22 20:36:25 2015 deb0ch
** Last update Thu Nov  5 17:27:00 2015 chauvo_t
*/

#include "kwrite.h"
#include "string.h"
#include "types.h"
#include "vga.h"

static uint32_t g_vga_cursor = 0;

void	vga_scroll()
{
	memcpy(VGA_BASE,
	       VGA_BASE + VGA_COORD(0, 1) * sizeof(vga_text_char_t),
	       VGA_COORD(0, VGA_HEIGHT - 1) * sizeof(vga_text_char_t));
	memset(VGA_BASE + VGA_COORD(0, VGA_HEIGHT - 1) * sizeof(vga_text_char_t),
	       0,
	       VGA_WIDTH * sizeof(vga_text_char_t));
	g_vga_cursor = VGA_COORD(0, VGA_HEIGHT - 1);
}

void	vga_clr()
{
	memset(VGA_BASE,
	       0,
	       VGA_WIDTH * VGA_HEIGHT * sizeof(vga_text_char_t));
	g_vga_cursor = 0;
}

void	kwrite_vga_coord(uint32_t x, uint32_t y, char c)
{
	vga_text_char_t		vc;

	if (x >= VGA_WIDTH || y >= VGA_HEIGHT)
		return;
	/* vc.vga.color.fg_color_rgb = 7; */
	/* vc.vga.color.fg_color_intensity = 0; */
	/* vc.vga.color.bg_color_rgb = 0; */
	/* vc.vga.color.bg_color_intensity = 0; */
	vc.vga.color.byte = VGA_LIGHT_BLUE;
	vc.vga.ascii = c;
	*((vga_text_char_t*)VGA_BASE + VGA_COORD(x, y)) = vc;
}

void	kwrite_vga(const char *buf, size_t size)
{
	while (size)
	{
		if (*buf == '\n')
			g_vga_cursor = VGA_COORD(0, VGA_ROW(g_vga_cursor) + 1);
		else
		{
			kwrite_vga_coord(VGA_COL(g_vga_cursor),
					 VGA_ROW(g_vga_cursor),
					 *buf);
			++g_vga_cursor;
		}
		if (g_vga_cursor >= VGA_WIDTH * VGA_HEIGHT)
			vga_scroll();
		--size;
		++buf;
	}
}
