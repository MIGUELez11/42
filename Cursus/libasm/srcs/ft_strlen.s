section .text
	global _ft_strlen   		;Define globaly ft_strlen for C

_ft_strlen:             		;Define function
	;rdi = parameter str
	mov rax, 0					;i = 0
	while:
		cmp byte[rdi + rax], 0	;if (str[i] === '\0')
		jz	end					;then goto end
								;else
		inc rax					;i++
		jmp while				;goto while again
	end:
		ret           			;return i