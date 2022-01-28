;Yiwei He mathlib.s 11/01/2021
global product
global power

section .text

product:
    xor	rax, rax
    xor r10, r10
    mov rdx, rdi

product_loop:
    cmp r10, rsi
    jge product_done
    add rax, rdi
    inc r10
    jmp product_loop

product_done:
    ret

power:
    mov rax, rdi
    mov rsi, rdx
    cmp r10,0
    jg power_loop
    mov rax, 1
    jmp power_done

power_loop:
    dec r10
    call power
    mov rdi, rax
    call product

power_done: 
    ret
