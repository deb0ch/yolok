##
## module.mk for yolok in yolok/src/stdio
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Sun Jul 12 14:05:19 2015 chauvo_t
##

THIS_DIR_L1	:= kstdio

MOD_SRC		:=	kprintf.c			\
			kprintf_format_specifiers1.c	\
			kprintf_format_specifiers2.c	\
			kputchar.c			\
			kputnbr_base.c			\
			kputnbr.c			\
			kputstr.c			\
			kputunsint_base.c		\
			kputunslong_base.c		\

SRCS		+= $(addprefix $(THIS_DIR_L0)/$(THIS_DIR_L1)/, $(MOD_SRC))

SUBDIRS		+= $(THIS_DIR_L0)/$(THIS_DIR_L1)/inc
