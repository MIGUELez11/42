section .text
    global _ft_strcmp

_ft_strcmp:
    ;rdi = parameter str1
    ;rsi = parameter str2
    mov rax, 0                      ;i = 0
    mov rbx, 0                      ;aux = 0
    while:
        mov dl, [rsi + rax]         ;aux = str2[i]
        cmp [rdi + rax], dl         ;Check:
        jg greater                  ;if (str1[i] > str2[i]) goto greater
        jl lower                    ;else if (str1[i] < str2[i]) goto lower
        cmp byte [rdi + rax], 0     ;else if (str[i] == '\0')
        jz  compare                 ;then goto compare
        cmp byte [rsi + rax], 0     ;else if (str2[i] == '\0')
        jz  compare                 ;then goto compare
                                    ;else
        inc rax                     ;i++
        jmp while                   ;goto while again
        compare:
            mov dl, [rdi + rax]    ;aux = str2[i]
            cmp dl, [rsi + rax]    ;Check:
            jg  greater            ;if (str1[i] > str2[i]) goto greater
            jl  lower              ;else if (str1[i] < str2[i]) goto lower
            jmp equal              ;else goto equal
            lower:
                mov rax, -1        ;return -1
                ret
            greater:
                mov rax, 1         ;return 1
                ret
            equal:
                mov rax, 0         ;return 0
                ret
                int 0x80