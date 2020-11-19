section .data
	msg db "a\0"

section .text
	global _hello_world, _suma, _print

_test:

	;Los 6 primeros parámetros se pasan por RDI, RSI, RDX, RCX, R8 y R9
	;El resto están en la pila
	push rbp       ;Almacenar el registro rbp en la pila
	mov rbp, rsp   ;Asignar el valor del registro apuntador rsp
	sub rsp, 8		;Reservar 8 bytes para variables locales

	; add rsp, 8		;ELiminar los 8 bytes de variables locales
	mov rsp, rbp   ;Restaurar el valor inicial de RSP con RBP
	pop rbp        ;Restaurar el valor inicial de rbp


	mov rax, 13    ;Establecer valor de retorno
	ret				;Return rax

_hello_world:
	mov rbx, "hello"
	push rbx
	pop rax
	ret

_suma:
	mov rax, [rdi]
	inc rax
	add rax, rsi
	mov [rdi], rax
	ret

_print:
	mov rax, 4 ;Print
	mov rbx, 1 ;FD
	mov rcx, msg	;Buff
	mov rdx, 2;Length
	int 80h	;Kernel


;Registers:

;32bits || 4bytes
;EAX EBX ECX EDX

;16 bits || 2bytes
;AX BX CX DXs