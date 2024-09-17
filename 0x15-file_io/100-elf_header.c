#include "elf.h"

/**
 * print_error - function to print errors
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}
/**
 * print_elf_header - print ELF header
 * @header: header
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	if (memcmp(header->e_ident, ELF_MAGIC, ELF_MAGIC_SIZE) != 0)
	{
		print_error("Not an ELF file");
		return;
	}

	print_elf_magic(header->e_ident);
	print_elf_class(header->e_ident[4]);
	print_elf_data(header->e_ident[5]);
	printf("Version:                           %d (current)\n",
		header->e_ident[6]);
	print_elf_osabi(header->e_ident[7]);
	printf("ABI Version:                       %d\n", header->e_ident[8]);
	print_elf_type(header->e_type);
	printf("Entry point address:               0x%lx\n", header->e_entry);
}
/**
 * print_elf_magic - print magic
 * @e_ident: char
 */
void print_elf_magic(const unsigned char *e_ident)
{
    printf("Magic:                             %.2x%.2x%.2x%.2x\n",
			e_ident[0], e_ident[1], e_ident[2], e_ident[3]);
}
/**
 * print_elf_class - print class
 * @class: class
 */
void print_elf_class(unsigned char class)
{
	printf("Class:                             ");
	switch (class)
	{
		case 1: printf("ELF32\n"); break;
		case 2: printf("ELF64\n"); break;
		default: print_error("Unknown class"); break;
	}
}
/**
 * print_elf_data - print data
 * @data: data
 */
void print_elf_data(unsigned char data)
{
	printf("Data:                              ");
	switch (data)
	{
		case 1: printf("2's complement, little endian\n"); break;
		case 2: printf("2's complement, big endian\n"); break;
		default: print_error("Unknown data encoding"); break;
	}
}
/**
 * print_elf_osabi - print OS/ABI
 * @osabi: OS/ABI
 */
void print_elf_osabi(unsigned char osabi)
{
	printf("OS/ABI:                            ");
	switch (osabi)
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
}
/**
 * print_elf_type - print type
 * @type: type
 */
void print_elf_type(unsigned int type)
{
	printf("Type:                              ");
	switch (type)
	{
		case 0x00: printf("NONE (None)\n"); break;
		case 0x01: printf("REL (Relocatable file)\n"); break;
		case 0x02: printf("EXEC (Executable file)\n"); break;
		case 0x03: printf("DYN (Shared object file)\n"); break;
		case 0x04: printf("CORE (Core file)\n"); break;
		default: printf("Unknown\n"); break;
		}
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
