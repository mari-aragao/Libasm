global ft_strdup
extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
ft_strdup:
    push rdi ; save the original pointer
    call ft_strlen wrt ..plt ; get the length of the string
    inc rax ; increment length to null terminator 

    mov rdi, rax ; save lenght in first argument
    call malloc wrt ..plt ; allocate memory

    test rax, rax ; check if malloc returned NULL
    jz error ; if NULL, jump to error

    pop rsi ; restore the original pointer
    mov rdi, rax ; move the allocated memory pointer to rdi

    call ft_strcpy wrt ..plt ; copy the string
    ret

error:
    pop rdi ; clean up the stack
    call __errno_location wrt ..plt ; get the address of errno
    mov dword [rax], 12 ; set errno = ENOMEM (12)
    xor rax, rax ; return null
    ret