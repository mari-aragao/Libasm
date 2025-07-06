global ft_write
extern __errno_location

section .text
ft_write:
    mov rax, 1 ; syscall number for write
    syscall ; call syscall

    cmp rax, 0 ; check if rax is below 0
    jl error ; if rax < 0, an error occurred
    ret

error:
    neg eax ; invert rax to get the error code
    mov ecx, eax ; save the error code in ecx
    call __errno_location wrt ..plt ; get the address of errno
    mov [rax], ecx ; set errno = error code
    
    mov rax, -1 ; return -1
    ret
