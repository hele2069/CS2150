; Yiwei He yh9vhg threexplusone.s 11/15/2021
; University of Virginia
; CS 2150 Pre-Lab 9
global threexplusone

section .data

xor rbx, rbx
xor rax, rax

section .text

threexplusone:
    cmp rdi, 1
    jne start
    ret

start:    
    mov r11, rdi
    and rdi, 1
    cmp rdi, 1
    je odd
    cmp rdi, 1
    jne even

odd:
    mov rdi, r11
    imul rdi, 3
    inc rdi
    jmp recurse

even:
    mov rax, r11
    mov rdx, 0
    mov r8, 2
    idiv r8
    mov rdi, rax
    jmp recurse

recurse:
    call threexplusone
    inc rbx
    mov rax, rbx
    ret
