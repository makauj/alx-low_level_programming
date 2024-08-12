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
void print_elf_header_info(const Elf64_Ehdr *header);
void error_exit1(const char *message);
void error_exit(int code, const char *message, const char *arg);
int open_file(const char *filename, int flags, mode_t mode);
void close_file(int fd);
void copy_file(int file_from, int file_to);
char *create_buffer(char *file);

#endif /* MAIN_H */
