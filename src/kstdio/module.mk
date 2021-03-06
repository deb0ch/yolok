##
## module.mk for yolok in yolok/src/stdio
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Fri Jul 10 16:07:51 2015 chauvo_t
## Last update Wed Jul 22 11:33:40 2015 deb0ch
##

THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

MOD_SRC  := kputchar.c         \
            kputnbr_base.c     \
            kputnbr.c          \
            kputstr.c          \
            kputunsint_base.c  \
            kputunslong_base.c \

SRCS  += $(addprefix $(THIS_DIR), $(MOD_SRC))

SUBDIRS  += $(THIS_DIR)inc
SUBDIRS  += $(THIS_DIR)kprintf

include $(THIS_DIR)kprintf/module.mk
