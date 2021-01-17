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
    cli     # disable interrupt

    # prepare the stack
	movl $kernel_stack, %esp
    and $0xFFFFFFF0, %esp       # 16 byte align
    
    # give parameters to kernel_main
    pushl %eax  # Magic
    pushl %ebx  # Multiboot structure

	call kernel_main

# apparently, this will never be reached
loop:
    cli
	hlt
	jmp loop


.section .bss
.space 64 * 1024;  # 64 KiB
kernel_stack:

