; Yiwei He yh9vhg 11/04/2021 linearSearch.s
; University of Virginia
; CS 2150 Post-Lab 8
; Spring 2018

	global linearSearch
	section .text

linearSearch:
    mov rax, -1
    xor r10, r10
    xor ecx, ecx

linearSearch_loop:
    cmp r10, rsi
    je end
    mov ecx, [rdi+4*r10]
    cmp ecx, edx
    je index
    inc r10
    jmp linearSearch_loop

index:
    mov rax, r10

end:
    ret