#ifndef ELF_H
#define ELF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

/**
 * struct - ELF header structure
 * 
 * Description: ELF header structure for 64-bit files
 */
typedef struct
{
	unsigned char e_ident[16];  /* Magic number and other information */
	uint16_t e_type;            /* Object file type */
	uint16_t e_machine;         /* Architecture */
	uint32_t e_version;         /* Object file version */
	uint64_t e_entry;           /* Entry point virtual address */
	uint64_t e_phoff;           /* Program header table file offset */
	uint64_t e_shoff;           /* Section header table file offset */
	uint32_t e_flags;           /* Processor-specific flags */
	uint16_t e_ehsize;          /* ELF header size in bytes */
	uint16_t e_phentsize;       /* Program header table entry size */
	uint16_t e_phnum;           /* Program header table entry count */
	uint16_t e_shentsize;       /* Section header table entry size */
	uint16_t e_shnum;           /* Section header table entry count */
	uint16_t e_shstrndx;        /* Section header string table index */
} Elf64_Ehdr;

void print_error(const char *message);
void print_elf_magic(const unsigned char *e_ident);
void print_elf_class(unsigned char class);
void print_elf_data(unsigned char data);
void print_elf_osabi(unsigned char osabi);
void print_elf_type(unsigned int type);

#define ELF_MAGIC_SIZE 4
static const unsigned char ELF_MAGIC[ELF_MAGIC_SIZE] = {0x7f, 'E', 'L', 'F'};

#endif /* ELF_H */
