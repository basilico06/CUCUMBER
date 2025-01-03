	extern print_str, alloc, print_unsigned_int, input_func, input_to_string, string_to_int
section .text
global Start_262262, DllMain
DllMain:
	ret
Fibonacci_262262:
	sub rsp, 12
	; ASSIGN res = math_expression
	
	; MATH EXPRESSION
	
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	
	; MATH EXPRESSION
	
	mov ecx , 2
	mov eax ,  [ rsp + 24 ]
	sub eax, ecx
	mov EAX, eax
	mov  DWORD[rsp+4] , EAX
	mov EAX, 0
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov ecx , EAX
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	
	; MATH EXPRESSION
	
	mov ecx , 1
	mov eax ,  [ rsp + 24 ]
	sub eax, ecx
	mov EAX, eax
	mov  DWORD[rsp+4] , EAX
	mov EAX, 0
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax , EAX
	add eax, ecx
	mov EAX, eax
	; ALLOCATION di resin posizione : 8
	mov  [ rsp + 0 ], EAX
	; return statment -> mette in una derivazione di eax 
	mov EAX,  [ rsp + 0 ]
	add rsp, 12
	ret
	
	
Start_262262:
	sub rsp, 12
	; ASSIGN res = 4
	mov EAX, 4
	; ALLOCATION di resin posizione : 8
	mov  [ rsp + 0 ], EAX
	xor rax, rax
	mov eax,  [ rsp + 0 ]
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	; return statment -> mette in una derivazione di eax 
	mov EAX,  [ rsp + 0 ]
	add rsp, 12
	ret
	
	
