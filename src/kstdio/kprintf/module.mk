##
## module.mk for yolok in yolok/src/kstdio/kprintf
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Wed Jul 22 11:30:16 2015 deb0ch
##

THIS_DIR_L1	:= kprintf

MOD_SRC		:=	kprintf.c			\
			kprintf_format_specifiers1.c	\
			kprintf_format_specifiers2.c	\

SRCS		+= $(addprefix $(THIS_DIR_L0)/$(THIS_DIR_L1)/, $(MOD_SRC))

SUBDIRS		+= $(THIS_DIR_L0)/$(THIS_DIR_L1)/inc
