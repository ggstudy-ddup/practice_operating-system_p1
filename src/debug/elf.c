#include "../include/debug/elf.h"

// get ELF information
elf_t get_ELF_from_multiboot(multiboot_t *mb)
{
    elf_t elf;
    elf_section_header_t *elf_sh = (elf_section_header_t*)(mb->addr);
    
    uint32_t shstrtab = elf_sh[mb->shndx].addr;
    for (int i = 0; i < mb->num; i++)
    {
        const char *name = (const char *)(shstrtab + elf_sh[i].name);
        // find the information in the multiboot struct that's provided by GRUB
        // extract str table and symbol table from the ELF
        if (!strcmp(name, ".strtab"))   // different
        {
            elf.strtab = (const char *)elf_sh[i].addr;
            elf.strtabsz = elf_sh[i].size;
        }
        if (!strcmp(name, ".symtab"))   // different
        {
            elf.symtab = (elf_symbol_t*)elf_sh[i].addr;
            elf.symtabsz = elf_sh[i].size;
        }
    }

    return elf;
}

const char * get_ELF_symbol(uint32_t addr, elf_t *elf_p)
{
    for (int i = 0; i < (elf_p->symtabsz / sizeof(elf_symbol_t)); i++)
    {
        if (ELF32_ST_TYPE(elf−>symtab[i].info) != 0x2)
            continue;
        // get the function name by its calling address
        if ((addr >= elf_p->symtab[i].value)                    // if true
        && (elf_p->symtab[i].value + elf_p->symtab[i].size)) {  // if not 0
            return (const char *)
            ((uint32_t)elf−>strtab + elf−>symtab[i].name);
        }
    }
    return NULL;
}


            
    
