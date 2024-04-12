SECTION .data
msg     db      'Hello world', 0Ah

SECTION .text
global _start

_start:
    mov eax, 10
    mov ebx, 20
    add eax, ebx
    ret
