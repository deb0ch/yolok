##
## module.mk for yolok in yolok/src/kstdio/kprintf
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Sun Nov 29 13:05:32 2015 chauvo_t
##

THIS_DIR_L1	:= kprintf

MOD_SRC		:=	kprintf.c			\
			kprintf_format_specifiers.c	\

SRCS		+= $(addprefix $(THIS_DIR_L0)/$(THIS_DIR_L1)/, $(MOD_SRC))

SUBDIRS		+= $(THIS_DIR_L0)/$(THIS_DIR_L1)/inc
