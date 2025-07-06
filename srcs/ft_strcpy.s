global ft_strcpy

section .text
ft_strcpy:
    xor rcx, rcx ; clear rcx (counter)

loop:
    mov al, [rsi, rcx] ; copy s1[counter] into al
    mov [rdi, rcx], al ; copy al to s2[counter]
    inc rcx ; increment counter
    cmp al, 0 ; check if al is null (end of string)
    jne loop ; repeat the loop

    mov rax, rdi ; return the pointer 
    ret
