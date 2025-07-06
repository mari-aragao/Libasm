global ft_strlen

section .text
ft_strlen:
    xor rax, rax ; clear rax (counter)

loop:
    cmp byte [rdi + rax], 0 ; check if the char null
    je end ; if it is null, jump to end       
    inc rax ; increment counter
    jmp loop ; repeat the loop

end:
    ret
