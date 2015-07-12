##
## module.mk for yolok in yolok/src
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:04:33 2015 chauvo_t
## Last update Sun Jul 12 13:28:23 2015 chauvo_t
##

SRCS		:=	crt0.S		\
			main.c		\
			segmentation.c	\
			serial.c	\
			utils.c

SUBDIRS		+=	inc		\
			printk		\
			stdio		\
			string

include $(SRCDIR)/printk/module.mk
include $(SRCDIR)/stdio/module.mk
include $(SRCDIR)/string/module.mk
