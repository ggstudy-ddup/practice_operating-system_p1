
.section .text
.extern kernel_main
.global loader

loader:
	mov $kernel_stack, %esp
	call kernel_main
loop:
	hlt
	jmp $loop

.section .bss

kernel_stack:

