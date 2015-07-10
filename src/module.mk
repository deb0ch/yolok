##
## module.mk for yolok in yolok/src
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:04:33 2015 chauvo_t
## Last update Fri Jul 10 17:20:24 2015 chauvo_t
##

THIS_DIR_L0	:= src

SRCS		:=	crt0.S		\
			main.c		\
			segmentation.c	\
			serial.c	\
			utils.c

CFLAGS		+= -I$(THIS_DIR_L0)

include $(THIS_DIR_L0)/printk/module.mk
include $(THIS_DIR_L0)/stdio/module.mk
include $(THIS_DIR_L0)/string/module.mk
