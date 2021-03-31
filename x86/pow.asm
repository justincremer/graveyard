global _start

section .data
    result db 0
section .text
_start:
    mov ebx, 1   ; ebx = 1
    mov ecx, 5   ; ecx = 4
label:
    add ebx, ebx ; exb += ebx
    dec ecx      ; ecx--
    cmp ecx, 0
    int 0x80     ; perform sys call   
    jg label     ; if (ecx == 0) jump(label)
    mov [result], ebx ; set result to be the result of our operation
    mov eax, 4   ; sys_write
    mov ebx, 1   ; stdout
    mov ecx, result ; move result into ecx
    mov edx, 1   ; number of bytes to write
    int 0x80     ; perform sys call   
    mov eax, 1   ; sys_exit
    mov ebx, 0   ; return 0
    int 0x80     ; perform sys call
    