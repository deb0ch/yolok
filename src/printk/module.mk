##
## module.mk for yolok in yolok/src/printk
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:01 2015 chauvo_t
## Last update Sun Jul 12 13:29:50 2015 chauvo_t
##

THIS_DIR_L0	:= printk

MOD_SRC		:=	printk.c			\

SRCS		+= $(addprefix $(THIS_DIR_L0)/, $(MOD_SRC))

SUBDIRS		+= $(THIS_DIR_L0)
