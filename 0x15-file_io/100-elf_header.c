#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
/**
 * print_error - function to print errors
 * @msg: error message
 *
 */

void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - function to check if file is an ELF file
 * @e_ident: first few characters in the file
 */

void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7F || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		print_error("Error: Not an ELF file");
	}
}

/**
 * print_elf_header - function to print ELF header
 * @header: headers
 */

void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:                             %s\n",
			header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	printf("Data:                              %s\n",
			header->e_ident[EI_DATA] == ELFDATA2LSB ?"2's complement, little endian" : "2's complement, big endian");

	printf("Version:                           %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %d\n", header->e_type);
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
	int fd;

	Elf64_Ehdr header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Error: Can't read file");
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		print_error("Error: Can't read ELF header");
	}

	check_elf(header.e_ident);
	print_elf_header(&header);

	close(fd);
	return (0);
}

