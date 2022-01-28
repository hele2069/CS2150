;Yiwei He yh9vhg 11/18/2021 binarySearch.s
global binarySearch

section .text

binarySearch:
    mov r8, rdx
    cmp rsi, rdx
    jg done             ;low>high, then ret

    mov rdx, 0
    mov rax, r8
    add rax, rsi        ;rax = low+high
    mov r9, 2
    idiv r9             ;rax = (low+high)/2
    mov rbx, rax
    mov rdx, r8
    cmp [rdi+rbx*4],ecx

    jl less
    jg greater
    je equal

less:
    mov rsi, rbx
    inc rsi
    jmp binarySearch

greater:
    mov rdx, rbx
    dec rdx
    jmp binarySearch

equal:
    mov rax, rbx
    ret

done:
    mov rax,-1
    ret