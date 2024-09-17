#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define ELF_MAGIC "\x7f""ELF"
#define ELF_MAGIC_SIZE 4

/**
 * struct - ELF header structure
 * DEscription: ELF header structure for 64-bit files 
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
/**
 * print_error - function to print errors
 */
void print_error(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(98);
}
/**
 * print_elf_header - function to print ELF headers
 * @header: header
 */
void print_elf_header(const Elf64_Ehdr *header) 
{
    if (memcmp(header->e_ident, ELF_MAGIC, ELF_MAGIC_SIZE) != 0)
    {
        print_error("Not an ELF file");
    }

    printf("Magic:   %.2x%.2x%.2x%.2x\n",
           header->e_ident[0], header->e_ident[1],
           header->e_ident[2], header->e_ident[3]);

    printf("Class:                             ");
    switch (header->e_ident[4])
    {
        case 1: printf("ELF32\n"); break;
        case 2: printf("ELF64\n"); break;
        default: print_error("Unknown class");
    }

    printf("Data:                              ");
    switch (header->e_ident[5])
    {
        case 1: printf("2's complement, little endian\n"); break;
        case 2: printf("2's complement, big endian\n"); break;
        default: print_error("Unknown data encoding");
    }

    printf("Version:                           %d (current)\n", header->e_ident[6]);

    printf("OS/ABI:                            ");
    switch (header->e_ident[7])
    {
        case 0: printf("UNIX - System V\n"); break;
        case 1: printf("UNIX - HP-UX\n"); break;
        case 2: printf("UNIX - NetBSD\n"); break;
        case 3: printf("UNIX - Linux\n"); break;
        case 6: printf("UNIX - Solaris\n"); break;
        case 7: printf("UNIX - AIX\n"); break;
        case 8: printf("UNIX - IRIX\n"); break;
        case 9: printf("UNIX - FreeBSD\n"); break;
        case 10: printf("UNIX - Tru64\n"); break;
        case 11: printf("ARM\n"); break;
        case 12: printf("Standards-based OS\n"); break;
        default: printf("Unknown\n"); break;
    }

    printf("ABI Version:                       %d\n", header->e_ident[8]);

    printf("Type:                              ");
    switch (header->e_type)
    {
        case 0x00: printf("NONE (None)\n"); break;
        case 0x01: printf("REL (Relocatable file)\n"); break;
        case 0x02: printf("EXEC (Executable file)\n"); break;
        case 0x03: printf("DYN (Shared object file)\n"); break;
        case 0x04: printf("CORE (Core file)\n"); break;
        default: printf("Unknown\n"); break;
    }

    printf("Entry point address:               0x%lx\n", header->e_entry);
}
/**
 * main - main function
 * @argc: arguments
 * @argv: pointer to argument string
 *
 * Return: 0 if successful, 1 on failure
 */


int main(int argc, char *argv[])
{
    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    Elf64_Ehdr header;
    ssize_t bytes_read;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }
    
    if (fd < 0)
    {
        perror("Error opening file");
        exit(98);
    }

    
    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read < 0)
    {
        perror("Error reading file");
        close(fd);
        exit(98);
    }
    if (bytes_read < (ssize_t)sizeof(header))
    {
        print_error("Error: Incomplete ELF header");
    }

    close(fd);
    print_elf_header(&header);

    return (0);
}
