section .text
	global  _ft_strcpy

_ft_strcpy:
	;rdi = parameter dest
	;rsi = parameter src
	mov rax, 0						;i = 0;
	while:
		mov rbx, [rsi + rax]	;aux = dst[i]
		mov [rdi + rax], rbx	;src[i] = aux
		cmp byte [rsi + rax], 0	;if (src[i] != '\0')
		jz	end						;then goto end
									;else
		inc rax						;i++
		jmp while					;goto while again
	end:
		mov	rax, rsi				;return = dst
		ret							;return