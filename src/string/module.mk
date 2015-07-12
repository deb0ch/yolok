##
## module.mk for yolok in /home/chauvo_t/Programming/Work_in_progress/Kernel/kfs/kfs-chauvo_t/src/string
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri Jul 10 16:36:51 2015 chauvo_t
## Last update Sun Jul 12 13:29:24 2015 chauvo_t
##

THIS_DIR_L0	:= string

MOD_SRC	:=	memset.c	\
		strcat.c	\
		strcmp.c	\
		strcpy.c	\
		strlen.c	\

SRCS	+=	$(addprefix $(THIS_DIR_L0)/, $(MOD_SRC))

SUBDIRS		+= $(THIS_DIR_L0)/inc
