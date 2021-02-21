section .text
    global _ft_strcmp
    extern _ft_write

_ft_strcmp:
    ; rdi = parameter str1
    ; rsi = parameter str2
    mov rax, 0                  ;i = 0
    mov dl, [rdi]               ;byte aux = str1
    cmp dl, 0                   ;if (aux == 0)
    jz byteCmp                  ;then goto byteCmp
    mov dl, [rsi]               ;byte aux = str2
    cmp dl, 0                   ;if (aux == 0)
    jz byteCmp                  ;then goto byteCmp
    ; byteCmp is needed because of \0 not compared with other chars on dword
    while:
        mov rbx, [rdi + rax]    ;dword aux1 = str1[i]
        mov rcx, [rsi + rax]    ;dword aux2 = str2[i]
        cmp rbx, rcx            ;diff = rbx - rcx
        jl  lower               ;if (diff < 0) goto lower
        jg  greater             ;if (diff > 0) goto greater
        cmp rbx, 0              ;if (!str1[i])
        jz  equal               ;then goto equal
        cmp rcx, 0              ;if (!str2[i])
        jz equal                ;then goto equal
        inc rax                 ;i++;
        jmp while               ;go back to while

    byteCmp:
        mov dl, byte [rdi]      ;byte aux = str1[0]
        cmp dl, byte [rsi]      ;byte aux = str2[0] - str1[0]
        jg  greater             ;if (aux > 0) then goto greater
        jl  lower               ;if (aux < 0) then goto lower
        je  equal               ;if (aux == 0) then goto equal
    lower:
        mov rax, -1             ;return -1
        ret
    greater:
        mov rax, 1              ;return 1
        ret
    equal:
        mov rax, 0              ;return 0
        ret