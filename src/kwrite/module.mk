##
## module.mk for yolok in yolok/src/kwrite
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Wed Jul 22 20:39:57 2015 deb0ch
##

THIS_DIR_L0	:= kwrite

MOD_SRC		:=	kwrite.c		\
			kwrite_vga.c		\

SRCS		+= $(addprefix $(THIS_DIR_L0)/, $(MOD_SRC))
