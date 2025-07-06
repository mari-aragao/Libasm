global ft_strcmp

section .text
ft_strcmp:
    xor rcx, rcx ; clear rcx(counter)

loop:
    mov al, [rdi + rcx] ; copy s1[counter] into al
    mov bl, [rsi + rcx] ; copy s2[counter] into bl

    cmp al, bl ; compare the bytes
    jne not_equal ; if different, jump to not_equal

    test al, al ; check if al is null (end of string)
    je equal ; if it is null, jump to equal
    
    inc rcx ; increment the counter
    jmp loop ; continue the loop

equal:
    xor rax, rax ; return 0
    ret

not_equal:
    movzx eax, al ; change al to eax (sign-extend)
    movzx ebx, bl ; change bl to ebx (sign-extend)
    sub rax, rbx ; subtract the bytes
    ja greater ; if the s1[counter] is greater, jump to greater
    jb lower ; if the s1[counter] is lower, jump to minor
    
    xor eax, eax ; if they are equal, return 0
    ret

greater:
    mov eax, 1 ; return 1
    ret

lower:
    mov eax, -1 ; return -1
    ret