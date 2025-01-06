	extern print_str, alloc, print_unsigned_int, input_func, input_to_string, string_to_int
section .text
global Start_262262, DllMain
DllMain:
	ret
Start_262262:
	sub rsp, 8
	mov rax , 19
	call alloc
	mov dword [rax] , 15
	mov byte [rax  + 4 + 0] ,104
	mov byte [rax  + 4 + 1] ,101
	mov byte [rax  + 4 + 2] ,108
	mov byte [rax  + 4 + 3] ,108
	mov byte [rax  + 4 + 4] ,111
	mov byte [rax  + 4 + 5] ,32
	mov byte [rax  + 4 + 6] ,119
	mov byte [rax  + 4 + 7] ,111
	mov byte [rax  + 4 + 8] ,114
	mov byte [rax  + 4 + 9] ,108
	mov byte [rax  + 4 + 10] ,100
	mov byte [rax  + 4 + 11] ,33
	mov byte [rax  + 4 + 12] ,33
	mov byte [rax  + 4 + 13] ,33
	mov byte [rax  + 4 + 15-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; return statment -> mette in una derivazione di eax 
	mov EAX, 0
	add rsp, 0
	jmp ext___Start_262262
	ext___Start_262262:
	add rsp, 8
	ret
	
	
