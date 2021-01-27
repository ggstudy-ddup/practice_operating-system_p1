#ifndef __INCLUDE_MULTIBOOT_H__
#define __INCLUDE_MULTIBOOT_H__

#include <types.h>

typedef
struct multiboot_t
{
    uint32_t flags; /* Multiboot version info */
    /*
     * Get available RAM info from BIOS
     * 
     * mem_lower - size of lower memory, unit is KiB (how can I describe this?)
     * mem_upper - size of upper memory, unit is KiB (how can I describe this again?)
     * lower memory starts from addr 0
     * upper memory starts from addr 1 MiB
     * Maximum of mem_lower is 640 KiB
     * Maximum of mem_upper is <max mem size> - 1 MiB (the value is not ensure)
     */
    uint32_t mem_lower;
    uint32_t mem_upper;

    uint32_t boot_device;   /* disk device where the system is boot from */
    uint32_t cmdline;       /* kernel command line */
    uint32_t mods_count;    /* list of boot mods */
    uint32_t mods_addr;

    /*
     * ELF head of the kernel's section
     */
    uint32_t num;
    uint32_t size;
    uint32_t addr;
    uint32_t shndx;

    /*
     * copied from hurlex-doc:
     * 以下两项指出保存由 BIOS 提供的内存分布的缓冲区的地址和长度
     * mmap_addr 是缓冲区的地址， mmap_length 是缓冲区的总大小
     * 缓冲区由一个或者多个下面的 mmap_entry_t 组成
    */
    uint32_t mmap_length;
    uint32_t mmap_addr;

    /* copied from hurlex-doc: */
    uint32_t drives_length;     /* 指出第一个驱动器结构的物理地址 */
    uint32_t drives_addr;       /* 指出第一个驱动器这个结构的大小 */
    uint32_t config_table;      /* ROM 配置表 */
    uint32_t boot_loader_name;  /* boot loader 的名字 */
    uint32_t apm_table;         /* APM 表 */
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint32_t vbe_mode;
    uint32_t vbe_interface_seg;
    uint32_t vbe_interface_off;
    uint32_t vbe_interface_len;
} __attribute__((__packed__)) multiboot_t;

/*
 * size 是相关结构的大小，单位是字节，它可能大于最小值 20
 * base_addr_low 是启动地址的低位，32base_addr_high 是高 32 位，启动地址总共有 64 位
 * length_low 是内存区域大小的低位，32length_high 是内存区域大小的高 32 位，总共是 64 位
 * type 是相应地址区间的类型，1 代表可用，所有其它的值代表保留区域 RAM
 */
typedef
struct mmap_entry_t {
    uint32_t size;          /* size 是不含 size 自身变量的大小 */
    uint32_t base_addr_low;
    uint32_t base_addr_high;
    uint32_t length_low;
    uint32_t length_high;
    uint32_t type;
} __attribute__((__packed__)) mmap_entry_t;

/* 声明全局的 multiboot * 指针 */
extern multiboot_t *glb_mboot_ptr;

#endif /* !__INCLUDE_MULTIBOOT_H__ */

