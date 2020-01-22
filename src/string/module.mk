##
## module.mk for yolok in /home/chauvo_t/Programming/Work_in_progress/Kernel/kfs/kfs-chauvo_t/src/string
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Fri Jul 10 16:36:51 2015 chauvo_t
## Last update Thu Jul 23 16:06:54 2015 deb0ch
##

THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

MOD_SRC  :=  memcpy.c  \
             memset.c  \
             memmove.c \
             strcat.c  \
             strcmp.c  \
             strcpy.c  \
             strlen.c

SRCS += $(addprefix $(THIS_DIR), $(MOD_SRC))

SUBDIRS  += $(THIS_DIR)inc
