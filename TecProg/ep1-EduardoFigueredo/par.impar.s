global _start

section .text 

_start:
    mov edx, 0x0
    mov eax, 0xA
    mov ebx, 0x2
    div ebx

;
syscall


mov rax, 60
mov rdi, 0


syscall

