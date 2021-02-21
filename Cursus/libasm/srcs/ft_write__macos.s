section .text
    global _ft_write
    extern ___error
    msg db "Hola", 0

_ft_write:
    ;RDI = fd
    ;RSI = buffer
    ;RDX = len
    mov rax, 0x02000004 ;say OS to print
    syscall             ;call kernel with rax
    jc error            ;if kernel returned error goto error
    ret                 ;else return
    error:
        push rbp        ;Push to stack
        mov rdi, rax    ;move to parameter error
        call ___error   ;Set errno
        mov  [rax], rdi ;add to rax the error code
        pop  rbp        ;reset stack
        mov  rax, -1    ;set return to -1
        ret