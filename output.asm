	extern print_str, alloc, print_unsigned_int, input_func, input_to_string, string_to_int
section .text
global Start_262262, DllMain
DllMain:
	ret
Fibonacci_262262:
	sub rsp, 12
	; IF STATMENT
	; SIMPLE CONDITION
	mov EAX,  [ rsp + 8 ]
	cmp EAX, 1
	jle ___jump_if_0
	jmp ___jump_end_1
	___jump_if_0:
	sub rsp, 0
	
	; MATH EXPRESSION
	
	mov r10d , 0
	mov r11d , 0
	add  r11d, r10d
	mov r10d ,r11d
	mov eax,r10d
	; return statment -> mette in una derivazione di eax 
	mov EAX,  [ rsp + 8 ]
	add rsp, 0
	jmp ext___Fibonacci_262262
	___jump_end_1:
	add rsp, 0
	; ASSIGN res = math_expression
	
	; MATH EXPRESSION
	
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	
	; MATH EXPRESSION
	
	mov eax, [ rsp + 24 ]
	push rax
	mov r10d , 1
	pop r11
	sub  r11d, r10d
	mov r10d ,r11d
	mov eax,r10d
	mov EAX, eax
	mov  DWORD[rsp+4] , EAX
	mov EAX,  [ rsp + 20 ]
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax,EAX
	push rax
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	
	; MATH EXPRESSION
	
	mov eax, [ rsp + 32 ]
	push rax
	mov r10d , 2
	pop r11
	sub  r11d, r10d
	mov r10d ,r11d
	mov eax,r10d
	mov EAX, eax
	mov  DWORD[rsp+4] , EAX
	mov EAX,  [ rsp + 28 ]
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax,EAX
	push rax
	pop r10
	pop r11
	add  r11d, r10d
	mov r10d ,r11d
	mov eax,r10d
	mov EAX, eax
	; ALLOCATION di resin posizione : 8
	mov  [ rsp + -8 ], EAX
	; return statment -> mette in una derivazione di eax 
	mov EAX,  [ rsp + -8 ]
	add rsp, 0
	jmp ext___Fibonacci_262262
	ext___Fibonacci_262262:
	add rsp, 12
	ret
	
	
Start_262262:
	sub rsp, 8
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 0
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 1
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 2
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 3
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 4
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 5
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 6
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 7
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 8
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 9
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	mov rax , 6
	call alloc
	mov dword [rax] , 2
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 2-1] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , dword [rax]
	call print_str
	; CALL FUNCTION Fibonacci_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, 10
	mov  DWORD[rsp+4] , EAX
	mov EAX, 1
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call Fibonacci_262262
	mov eax, EAX
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	; return statment -> mette in una derivazione di eax 
	mov EAX, 0
	add rsp, 0
	jmp ext___Start_262262
	ext___Start_262262:
	add rsp, 8
	ret
	
	
