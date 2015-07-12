##
## module.mk for yolok in yolok/src/stdio
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Sun Jul 12 13:29:06 2015 chauvo_t
##

THIS_DIR_L0	:= stdio

MOD_SRC		:=	printf.c			\
			printf_format_specifiers1.c	\
			printf_format_specifiers2.c	\
			putchar.c			\
			putnbr_base.c			\
			putnbr.c			\
			putstr.c			\
			putunsint_base.c		\
			putunslong_base.c		\

SRCS		+= $(addprefix $(THIS_DIR_L0)/, $(MOD_SRC))

SUBDIRS		+= $(THIS_DIR_L0)/inc
