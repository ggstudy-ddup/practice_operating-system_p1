.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern kernel_main
.global loader

loader:
	mov $kernel_stack, %esp
    pushl %eax
    pushl %ebx
	call kernel_main
loop:
    cli
	hlt
	jmp loop


.section .bss
.space 2*1024*1024;  # 2 MiB
kernel_stack:

