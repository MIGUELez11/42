section .text
    global _ft_read
    extern ___error

_ft_read:
    ;RDI = fd
    ;RSI = buffer
    ;RDX = len
    mov rax, 0x02000003 ;say OS to read
    syscall             ;call kernel with rax
    jc error            ;if kernel returned error goto error
    ret                 ;else return
    error:
        mov rdi, rax    ;move to parameter error
        call ___error   ;Set errno
        mov  [rax], rdi ;add to rax the error code
        mov  rax, -1    ;set return to -1
        ret