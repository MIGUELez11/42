section .text
    global _ft_strdup
    extern _malloc, _ft_strlen, _ft_strcpy

_ft_strdup:
    ;RDI str
    call _ft_strlen
    inc rax
    push rdi
    mov rdi, rax
    call _malloc
    pop rbx
    cmp rax, 0
    jz  end
    mov rdi, rax
    mov rsi, rbx
    call _ft_strcpy
    end:
        ret