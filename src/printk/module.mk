##
## module.mk for yolok in yolok/src/printk
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:01 2015 chauvo_t
## Last update Fri Jul 10 17:15:30 2015 chauvo_t
##

THIS_DIR_L1	:= printk

MOD_SRC		:=	printk.c			\

SRCS		+= $(addprefix $(THIS_DIR_L1)/, $(MOD_SRC))

CFLAGS		+= -I$(THIS_DIR_L0)/$(THIS_DIR_L1)
