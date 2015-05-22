##
## Makefile<kfs-chauvo_t> for YoloKernel in /home/chauvo_t/Programming/Work_in_progress/Kernel/kernel_from_scratch/kfs-chauvo_t
## 
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
## 
## Started on  Fri May 22 15:19:03 2015 chauvo_t
## Last update Fri May 22 17:44:16 2015 chauvo_t
##

CXX			:= gcc
QEMU			:= qemu-system-x86_64

SRCDIR			:= src
OBJDIR			:= build
HDRDIR			:= include

SRCS			:=	main.c			\
				crt0.S

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJS			:= $(OBJS:.S=.o)
SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

DEPS			:= $(OBJS:.o=.d)

CFLAGS			+= -Wextra -Wall -W
CFLAGS			+= $(addprefix -I./, $(HDRDIR))
CFLAGS			+= -MD
CFLAGS			+= -m32 -nostdinc -fno-builtin -fno-stack-protector # -target i386-none-eabi
CFLAGS			+= -mno-mmx -mno-3dnow -mno-sse
debug: CFLAGS		+= -g -g3 -ggdb

LDFLAGS			+= -T kfs.ld
LDFLAGS			+= -nostdinc -fno-builtin -fno-stack-protector # -target i386-none-eabi
LDFLAGS			+= -mno-mmx -mno-3dnow -mno-sse # -mno-see2 -mno-see3
LDFLAGS			+= -nostdlib
debug: LDFLAGS		+= -g -g3 -ggdb

TMPS			:=	$(OBJS)			\
				$(OBJS:.o=.d)

VDISK			:= disk.img
NAME			:= yolokernel.elf

all:		$(NAME)

boot: all
	$(QEMU) -kernel $(NAME) -nographic # -hda $(VDISK) -append "root=/dev/sda console=ttyS0"

debug:	re
	$(QEMU) -kernel $(NAME) -nographic -s -S # -hda $(VDISK) -append "root=/dev/sda console=ttyS0"

-include $(DEPS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.S
		$(COMPILE.c) $(OUTPUT_OPTION) $<

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
		$(COMPILE.c) $(OUTPUT_OPTION) $<

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
		mkdir -p $(OBJDIR)

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