##
## module.mk for yolok in yolok/src
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:04:33 2015 chauvo_t
## Last update Fri Dec 18 12:45:30 2015 chauvo_t
##

SRCS		:=	crt0.S			\
			irq.c			\
			interrupts.c		\
			interrupt_handlers.s	\
			keyboard.c		\
			main.c			\
			pit.c			\
			segmentation.c		\
			serial.c		\
			utils.c

SUBDIRS		+=	inc		\
			kstdio		\
			kwrite		\
			string

include $(SRCDIR)/kstdio/module.mk
include $(SRCDIR)/kwrite/module.mk
include $(SRCDIR)/string/module.mk
