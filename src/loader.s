.section .text
.extern kernel_main
.global loader

loader:
	mov $kernel_stack, %esp
	call kernel_main
loop:
    cli
	hlt
	jmp loop


.section .bss
.space 2*1024*1024;  # 2 MiB
kernel_stack:

