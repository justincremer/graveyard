global _start

section .data
    addr db "yellow"
section .text
_start:
    mov [addr], byte 'H'   ; replace addr[0] with 'H'
    mov [addr+5], byte '!' ; replace addr[5] with '!'
    mov eax, 4    ; sys_write
    mov ebx, 1    ; stdout
    mov ecx, addr ; bytes to write
    mov edx, 6    ; number of bytes to write
    int 0x80      ; perform sys call
    mov eax, 1    ; sys_exit
    mov ebx, 0    ; return 0
    int 0x80      ; perform sys call