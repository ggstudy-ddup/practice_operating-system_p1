#ifndef __INCLUDE_ELF_H__
#define __INCLUDE_ELF_H__

#include <types.h>
#include <multiboot.h>

#define ELF32_ST_TYPE(i) ((i) & 0xF)

/* ELF Section Header */
typedef
struct elf_section_header_t
{
    uint32_t name;
    uint32_t type;
    uint32_t flags;
    uint32_t addr;
    uint32_t offset;
    uint32_t size;
    uint32_t link;
    uint32_t info;
    uint32_t addralign;
    uint32_t entsize;
} __attribute__((__packed__)) elf_section_header_t;

// ELF format symbols
typedef
struct elf_symbol_t
{
    uint32_t name;
    uint32_t value;
    uint32_t size;
    uint8_t info;
    uint8_t other;
    uint16_t shndx;
} __attribute__((__packed__)) elf_symbol_t;

// ELF information
typedef
struct elf_t
{
    elf_symbol_t *symtab;
    uint32_t     symtabsz;
    const char   *strtab;
    uint32_t     strtabsz;
} elf_t;

/* Get ELF information from the multiboot structure */
elf_t get_ELF_from_multiboot(multiboot *ptr);

/* Check ELF symbol */
const char * get_ELF_symbol(uint32_t addr, elf_t *ptr);

#endif  /* !__INCLUDE_ELF_H__ */
