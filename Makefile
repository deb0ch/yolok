##
## Makefile for yolok in yolok/
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Fri May 22 15:19:03 2015 chauvo_t
## Last update Sat Jul 11 12:48:28 2015 chauvo_t
##

CXX			:= gcc
QEMU			:= qemu-system-x86_64 -append "root=/dev/sda console=ttyS0" -serial stdio

SRCDIR			:= src
OBJDIR			:= build

# Yes, this line is needed.
CFLAGS			:=
CFLAGS			+= -W -Wall -Wextra -Werror
CFLAGS			+= -MD
CFLAGS			+= -m32 -nostdinc -fno-builtin -fno-stack-protector
CFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
debug: CFLAGS		+= -g -g3 -ggdb

# Yes, this line is needed.
LDFLAGS			:=
LDFLAGS			+= -T kfs.ld
LDFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
LDFLAGS			+= -nostdlib -fno-stack-protector
LDFLAGS			+= -m32 -Wl,--build-id=none
debug: LDFLAGS		+= -g -g3 -ggdb

# Yes, this line is needed.
SRCS			:=

include $(SRCDIR)/module.mk

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

OBJS			:= $(OBJS:.S=.o)

DEPS			:= $(OBJS:.o=.d)

TMPS			:= $(OBJS) $(OBJS:.o=.d)

VDISK			:= disk.img
NAME			:= yolok

all: $(NAME)

boot: all
	$(QEMU) -kernel $(NAME) # -hda $(VDISK)

debug:	re
	$(QEMU) -kernel $(NAME) -s -S # -hda $(VDISK)

-include $(DEPS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.S
	@printf "[\033[0;32mCompiling\033[0m] % 55s\n" $< | tr ' ' '.'
	@$(COMPILE.c) $(OUTPUT_OPTION) $<

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@printf "[\033[0;32mCompiling\033[0m] % 55s\n" $< | tr ' ' '.'
	@$(COMPILE.c) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS)
	@printf "[\033[0;32mCompiler flags\033[0m] % 50s\n" | tr ' ' '.'
	@echo $(CFLAGS)
	@printf "[\033[0;34mLinker flags\033[0m] % 52s\n" | tr ' ' '.'
	@echo $(LDFLAGS)
	@printf "[\033[0;34mLinking\033[0m] % 57s\n" $(NAME) | tr ' ' '.'
	@$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@for dir in $(SUBDIRS);			\
	do					\
		mkdir -p $(OBJDIR)/$$dir;	\
	done

clean:
	@rm -f $(TMPS)
	@printf "[\033[0;31mDeleted\033[0m] % 57s\n" $(OBJS) | tr ' ' '.'

fclean:	clean
	@rm -f $(NAME)
	@printf "[\033[0;35mRemoved\033[0m] % 57s\n" $(NAME) | tr ' ' '.'

re:	fclean all

mkdisk:
	rm -f $(VDISK)
	dd if=/dev/zero of=$(VDISK) bs=1M count=16
	mkfs.ext4 $(VDISK) -L root

.PHONY:	all clean fclean re showflags
