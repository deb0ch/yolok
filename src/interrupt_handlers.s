
extern interrupts_handler

%macro interrupt_no_error 1	; macro taking one parameter
[GLOBAL isr%1]			; %1 = macro first parameter
isr%1:
        push 0xdead0000		; Push dummy value when there is no error code
        push %1			; interrupt_id
	jmp context_saving
%endmacro

%macro interrupt_error 1	; macro taking one parameter
[GLOBAL isr%1]			; %1 = macro first parameter
isr%1:
				;  Do not push anything if there is an error code
        push %1			; interrupt_id
	jmp context_saving
%endmacro

;; Intel manual Vol. 3A 6-3 (pdf p2098) table 6:
;; only interrupts 8, 10 to 14 inclusive and 17 push
;; an additionnal error code on the stack
	interrupt_no_error 0	; Interrupts 0 to 7 do not have error code
	interrupt_no_error 1
	interrupt_no_error 2
	interrupt_no_error 3
	interrupt_no_error 4
	interrupt_no_error 5
	interrupt_no_error 6
	interrupt_no_error 7
	interrupt_error    8	; Interrupt 8 has error code
	interrupt_no_error 9	; Interrupt 9 has no error code
	interrupt_error    10	; Interrupts 10 to 14  have error code
	interrupt_error    11
	interrupt_error    12
	interrupt_error    13
	interrupt_error    14
	interrupt_no_error 15	; Interrupt 15 has no error code
	interrupt_no_error 16	; Interrupt 16 has no error code
	interrupt_error    17	; Interrupt 17 has error code

;; All other interrupts have no error codes
%assign i 18
%rep 238
	interrupt_no_error i
%assign i i + 1
%endrep

context_saving:
	pusha			; save general purpose registers
	push gs
	push fs
	push es
	push ds
	push esp		; push pointer to saved context as 1st argument
        call interrupts_handler
	pop eax
	pop ds
	pop es
	pop fs
	pop gs
	popa
	add esp, 8
	iret
