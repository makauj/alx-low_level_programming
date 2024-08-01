section .data
	hello db "Hello, Holberton", 0      ; Null-terminated string

section .text
	global _start

extern printf

_start:
	; Set up the arguments for printf
	; printf("Hello, Holberton\n")
	mov rdi, hello     ; The first argument to printf is the format string
	xor rax, rax       ; Clear rax register (required by the calling convention)

	; Call printf
	call printf

	; Exit the program
	mov rax, 60        ; syscall number for exit
	xor rdi, rdi       ; exit code 0
	syscall            ; invoke system call
