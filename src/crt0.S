#define MAGIC 0x1badb002
#define FLAGS 0x7

	.section .multiboot
	.align	4
	.long	MAGIC
	.long	FLAGS
	.long	-(MAGIC + FLAGS)
	.section .text
	.global _start
_start:
	push %ebx
	push %eax
	call yolomain
	hlt
