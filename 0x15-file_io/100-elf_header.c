#include "main.h"

/**
 * error_exit - Prints an error message to stderr and exits with code 98.
 * @message: The error message to print.
 */
void error_exit1(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header_info - Prints the ELF header information.
 * @header: Pointer to the ELF header structure.
 */

void print_elf_header_info(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	printf("%02x%c", header->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid class\n");
			break;
	}

	printf("Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid data encoding\n");
			break;
	}

	printf("Version:                           %d (current)\n", 
			header->e_ident[EI_VERSION]);

	printf("OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		default:
			printf("Other\n");
			break;
	}

	printf("ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);

	printf("Type:                              ");
	switch (header->e_type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown type\n");
			break;
	}

	printf("Entry point address:               0x%lx\n",
			(unsigned long)header->e_entry);
	}
/**
 * main - main function
 * @argc: arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		error_exit1("Usage: elf_header elf_filename");
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error_exit1("Error: Can't read from file");
	}

	if (lseek(fd, 0, SEEK_SET) == (off_t) -1)
	{
		error_exit1("Error: Can't lseek");
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit1("Error: Can't read ELF header");

	/* Verify it is an ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		error_exit1("Error: Not an ELF file");
	}

	/* Print ELF header information */
	print_elf_header_info(&header);

	if (close(fd) == -1)
		error_exit1("Error: Can't close file");

	return (0);
}

