##
## Makefile for yolok in yolok/
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Fri May 22 15:19:03 2015 chauvo_t
## Last update Sun Jul 12 17:18:25 2015 chauvo_t
##

CXX			:= gcc
RM			:= rm -rf
QEMU			:= qemu-system-x86_64 -append "root=/dev/sda console=ttyS0" -serial stdio

SRCDIR			:= src
OBJDIR			:= build

# These lines are needed to set immediate evaluation for
# these variables, instead of deferred evaluation which is unsuitable.
SRCS			:=
SUBDIRS			:=
CFLAGS			:=
LDFLAGS			:=

include $(SRCDIR)/module.mk

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

OBJS			:= $(OBJS:.S=.o)

DEPS			:= $(OBJS:.o=.d)

TMPS			:= $(OBJS) $(OBJS:.o=.d)

CFLAGS			+= -W -Wall -Wextra -Werror
CFLAGS			+= -O2
CFLAGS			+= -MD
CFLAGS			+= -m32 -nostdinc -fno-builtin -fno-stack-protector
CFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
debug: CFLAGS		+= -g -g3 -ggdb
CFLAGS			+= $(addprefix -I./$(SRCDIR)/, $(SUBDIRS))

LDFLAGS			+= -T kfs.ld
LDFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
LDFLAGS			+= -nostdlib -fno-stack-protector
LDFLAGS			+= -m32 -Wl,--build-id=none
debug: LDFLAGS		+= -g -g3 -ggdb

VDISK			:= disk.img

NAME			:= yolok

all: showflags $(NAME)

showflags:
	@printf "[\033[0;33mCompiler flags\033[0m] %s\n"
	@echo $(CFLAGS)

boot: all
	$(QEMU) -kernel $(NAME) # -hda $(VDISK)

debug:	re
	$(QEMU) -kernel $(NAME) -s -S # -hda $(VDISK)

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.S
	@printf "[\033[0;32mCompiling\033[0m] %s\n" $<
	@$(COMPILE.c) $(OUTPUT_OPTION) $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "[\033[0;32mCompiling\033[0m] %s\n" $<
	@$(COMPILE.c) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS)
	@printf "[\033[0;33mLinker flags\033[0m] %s\n"
	@echo $(LDFLAGS)
	@printf "[\033[0;34mLinking\033[0m] %s\n" $(NAME)
	@$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@for dir in $(SUBDIRS);			\
	do					\
		mkdir -p $(OBJDIR)/$$dir;	\
	done

clean:
	@$(RM) $(TMPS)
	@printf "[\033[0;31mDeleted\033[0m] %s\n" $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJDIR)
	@printf "[\033[0;35mRemoved\033[0m] %s\n" $(NAME)
	@printf "[\033[0;35mRemoved\033[0m] %s\n" $(OBJDIR)

re:	fclean all

mkdisk:
	$(RM) $(VDISK)
	dd if=/dev/zero of=$(VDISK) bs=1M count=16
	mkfs.ext4 $(VDISK) -L root

.PHONY:	all clean fclean re showflags
