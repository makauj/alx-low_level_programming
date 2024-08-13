#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _strlen(const char *s);
int main(int argc, char *argv[]);
void check_elf(unsigned char *e_ident);
void print_error(const char *msg);
void print_elf_header(Elf64_Ehdr *header);

#endif /* MAIN_H */
