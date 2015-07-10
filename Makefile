##
## Makefile<kfs-chauvo_t> for YoloKernel in yolok/
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Fri May 22 15:19:03 2015 chauvo_t
## Last update Fri Jul 10 17:23:29 2015 chauvo_t
##

CXX			:= gcc
QEMU			:= qemu-system-x86_64 -append "root=/dev/sda console=ttyS0" -serial stdio

SRCDIR			:= src
OBJDIR			:= build

CFLAGS			:=
CFLAGS			+= $(addprefix -I./, $(addprefix $(SRCDIR)/, $(SUBDIRS)))
CFLAGS			+= -W -Wall -Wextra
CFLAGS			+= -MD
CFLAGS			+= -m32 -nostdinc -fno-builtin -fno-stack-protector
CFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
debug: CFLAGS		+= -g -g3 -ggdb

LDFLAGS			+= -T kfs.ld
LDFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
LDFLAGS			+= -nostdlib -fno-stack-protector
LDFLAGS			+= -m32 -Wl,--build-id=none
debug: LDFLAGS		+= -g -g3 -ggdb

#Sources (SRCS) definition and subdirectories creation is handle in submodules.
include $(SRCDIR)/module.mk

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

OBJS			:= $(OBJS:.S=.o)

DEPS			:= $(OBJS:.o=.d)

TMPS			:= $(OBJS) $(OBJS:.o=.d)

VDISK			:= disk.img
NAME			:= yolok

all:		$(NAME)

test:
	@echo $(SRCS)
	@echo $(CFLAGS)

boot: all
	$(QEMU) -kernel $(NAME) # -hda $(VDISK)

debug:	re
	$(QEMU) -kernel $(NAME) -s -S # -hda $(VDISK)

-include $(DEPS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.S
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(NAME):	$(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@for dir in $(SUBDIRS);			\
	do					\
		mkdir -p $(OBJDIR)/$$dir;	\
	done

clean:
	@rm -f $(TMPS)
	@echo "Object files cleaned"

fclean:	clean
	@rm -f $(NAME)
	@echo "Executable cleaned"

re:	fclean all

mkdisk:
	rm -f $(VDISK)
	dd if=/dev/zero of=$(VDISK) bs=1M count=16
	mkfs.ext4 $(VDISK) -L root

.PHONY:	all clean fclean re
