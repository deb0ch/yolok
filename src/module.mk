##
## module.mk for yolok in yolok/src
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:04:33 2015 chauvo_t
## Last update Wed Jul 22 12:11:18 2015 deb0ch
##

SRCS		:=	crt0.S		\
			main.c		\
			segmentation.c	\
			serial.c	\
			utils.c

SUBDIRS		+=	inc		\
			kstdio		\
			kwrite		\
			string

include $(SRCDIR)/kstdio/module.mk
include $(SRCDIR)/kwrite/module.mk
include $(SRCDIR)/string/module.mk
