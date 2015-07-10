##
## module.mk for yolok in yolok/src/stdio
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Fri Jul 10 17:16:23 2015 chauvo_t
##

THIS_DIR_L1	:= stdio

MOD_SRC		:=	printf.c			\
			printf_format_specifiers1.c	\
			printf_format_specifiers2.c	\
			putchar.c			\
			putnbr_base.c			\
			putnbr.c			\
			putstr.c			\
			putunsint_base.c		\
			putunslong_base.c		\

SRCS		+= $(addprefix $(THIS_DIR_L1)/, $(MOD_SRC))

CFLAGS		+= -I$(THIS_DIR_L0)/$(THIS_DIR_L1)
