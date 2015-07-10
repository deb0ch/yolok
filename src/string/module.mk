##
## module.mk for yolok in /home/chauvo_t/Programming/Work_in_progress/Kernel/kfs/kfs-chauvo_t/src/string
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:36:51 2015 chauvo_t
## Last update Fri Jul 10 17:38:56 2015 chauvo_t
##

THIS_DIR_L1	:= string

MOD_SRC	:=	memset.c	\
		strcat.c	\
		strcmp.c	\
		strcpy.c	\
		strlen.c	\

SRCS	+=	$(addprefix $(THIS_DIR_L1)/, $(MOD_SRC))

CFLAGS		+= -I$(THIS_DIR_L0)/$(THIS_DIR_L1)
