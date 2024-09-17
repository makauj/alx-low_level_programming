# ELF
## Question
Write a program that displays the information contained in the ELF header at the start of an ELF file.

	- Usage: elf_header elf_filename
	- Displayed information: (no less, no more, do not include trailing whitespace)
		- Magic
		- Class
		- Data
		- Version
		- OS/ABI
		- ABI Version
		- Type
		- Entry point address
	- Format: the same as readelf -h (version 2.26.1)
	- If the file is not an ELF file, or on error, exit with status code 98 and display a comprehensive error message to stderr
	- You are allowed to use lseek once
	- You are allowed to use read a maximum of 2 times at runtime
	- You are allowed to have as many functions as you want in your source file
	- You are allowed to use printf

man elf, readelf

### Overview

This program reads and displays information from the header of an ELF (Executable and Linkable Format) file. ELF files are commonly used for executables, object code, shared libraries, and core dumps in Unix-like systems.

### Code Breakdown

#### 1. **Includes and Function Declarations**

```c
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
```

- **`#include <elf.h>`**: This header defines the structures and constants used to interpret ELF files.
- **`#include <sys/types.h>`**: Provides definitions for data types used in system calls.
- **`#include <sys/stat.h>`**: Contains constants and macros related to file attributes.
- **`#include <fcntl.h>`**: Provides file control options (like `O_RDONLY`).
- **`#include <unistd.h>`**: Defines various symbolic constants and types (like `close`).
- **`#include <stdio.h>`**: Includes standard I/O functions (like `printf`).
- **`#include <stdlib.h>`**: Contains functions for memory allocation, process control, conversions, etc. (like `malloc`, `exit`).

```c
void check_elf(const unsigned char *e_ident);
void print_magic(const unsigned char *e_ident);
void print_class(const unsigned char *e_ident);
void print_data(const unsigned char *e_ident);
void print_version(const unsigned char *e_ident);
void print_osabi(const unsigned char *e_ident);
void print_abi(const unsigned char *e_ident);
void print_type(unsigned int e_type, const unsigned char *e_ident);
void print_entry(unsigned long int e_entry, const unsigned char *e_ident);
void close_elf(int elf);
```

These are the declarations of the functions used in the program. Each function has a specific purpose related to processing the ELF file header.

#### 2. **Check ELF File**

```c
void check_elf(const unsigned char *e_ident)
{
    if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}
```

- **Purpose**: To verify that the file is an ELF file.
- **Explanation**: The ELF file format starts with a magic number `0x7f 'E' 'L' 'F'`. If these bytes do not match, it prints an error message and exits.

#### 3. **Print Magic Numbers**

```c
void print_magic(const unsigned char *e_ident)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");
}
```

- **Purpose**: To print the magic numbers from the ELF header.
- **Explanation**: Magic numbers are the first few bytes of the ELF header. They are printed in hexadecimal format.

#### 4. **Print Class**

```c
void print_class(const unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32:  printf("ELF32\n"); break;
        case ELFCLASS64:  printf("ELF64\n"); break;
        default:          printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}
```

- **Purpose**: To print the class (32-bit or 64-bit) of the ELF file.
- **Explanation**: The `EI_CLASS` byte indicates whether the file is a 32-bit or 64-bit ELF file.

#### 5. **Print Data Encoding**

```c
void print_data(const unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE:   printf("none\n"); break;
        case ELFDATA2LSB:   printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB:   printf("2's complement, big endian\n"); break;
        default:           printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}
```

- **Purpose**: To print the data encoding format (endianess) of the ELF file.
- **Explanation**: `EI_DATA` indicates whether the ELF file uses little-endian or big-endian format.

#### 6. **Print Version**

```c
void print_version(const unsigned char *e_ident)
{
    printf("  Version:                           %d", e_ident[EI_VERSION]);
    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}
```

- **Purpose**: To print the ELF version.
- **Explanation**: `EI_VERSION` contains the version of the ELF format. If it matches `EV_CURRENT`, it’s the current version.

#### 7. **Print OS/ABI**

```c
void print_osabi(const unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:        printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX:        printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD:      printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX:       printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS:     printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX:        printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD:     printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64:       printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM:         printf("ARM\n"); break;
        case ELFOSABI_STANDALONE:  printf("Standalone App\n"); break;
        default:                  printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}
```

- **Purpose**: To print the OS/ABI identifier.
- **Explanation**: `EI_OSABI` indicates the operating system or ABI that the ELF file is intended for.

#### 8. **Print ABI Version**

```c
void print_abi(const unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}
```

- **Purpose**: To print the ABI (Application Binary Interface) version.
- **Explanation**: `EI_ABIVERSION` indicates the ABI version used.

#### 9. **Print Type**

```c
void print_type(unsigned int e_type, const unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("  Type:                              ");
    switch (e_type)
    {
        case ET_NONE:   printf("NONE (None)\n"); break;
        case ET_REL:    printf("REL (Relocatable file)\n"); break;
        case ET_EXEC:   printf("EXEC (Executable file)\n"); break;
        case ET_DYN:    printf("DYN (Shared object file)\n"); break;
        case ET_CORE:   printf("CORE (Core file)\n"); break;
        default:        printf("<unknown: %x>\n", e_type);
    }
}
```

- **Purpose**: To print the type of ELF file.
- **Explanation**: `e_type` indicates the file type (e.g., executable, shared object). If the data is in big-endian format, the type value is adjusted.

#### 10. **Print Entry Point**

```c
void print_entry(unsigned long int e_entry, const unsigned char *e_ident)
{
    printf("  Entry point address:               ");
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
    else
        printf("%#lx\n", e_entry);
}
```

- **Purpose**: To print the entry point address of the ELF file.
- **Explanation**: The entry point is where the execution starts. The address is formatted based on the endianness and class (32-bit or 64-bit).

#### 11. **Close ELF File**

```c
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
        exit(

98);
    }
}
```

- **Purpose**: To close the ELF file descriptor.
- **Explanation**: Properly closes the file and prints an error message if it fails.

#### 12. **Main Function**

```c
int main(int argc, char *argv[])
{
    Elf64_Ehdr *header;
    int fd, r;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        close_elf(fd);
        dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
        exit(98);
    }

    r = read(fd, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        close_elf(fd);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    check_elf(header->e_ident);
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    print_class(header->e_ident);
    print_data(header->e_ident);
    print_version(header->e_ident);
    print_osabi(header->e_ident);
    print_abi(header->e_ident);
    print_type(header->e_type, header->e_ident);
    print_entry(header->e_entry, header->e_ident);

    free(header);
    close_elf(fd);
    return (0);
}
```

- **Purpose**: This is the entry point of the program. It processes the ELF file specified as a command-line argument.
- **Explanation**:
  - **Argument Check**: Ensures that the program is called with exactly one argument (the ELF file path).
  - **Open File**: Opens the ELF file.
  - **Allocate Memory**: Allocates memory for the ELF header.
  - **Read Header**: Reads the ELF header from the file.
  - **Check ELF**: Validates that the file is an ELF file.
  - **Print Information**: Prints various pieces of information about the ELF file.
  - **Clean Up**: Frees allocated memory and closes the file.

### Summary

- The program reads the ELF header from a file and prints its contents in a human-readable format.
- Each function in the code handles a specific part of the ELF header or file operations.
- Error handling ensures that the program exits with an appropriate message if something goes wrong (e.g., file not found, memory allocation failure).

I hope this helps clarify how the code works! If you have any more questions or need further explanation on any part, feel free to ask.
