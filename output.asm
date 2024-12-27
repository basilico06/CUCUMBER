section .text
global Start_262262, DllMain
DllMain:
	ret
add_262262:
	sub rsp, 12
	; ASSIGN a = 11
	mov EAX, 11
	; ALLOCATION di ain posizione : 8
	mov DWORD [ rsp + 0 ], EAX
	; IF STATMENT
	; SIMPLE CONDITION
	mov EAX, DWORD [ rsp + 8 ]
	cmp EAX, 0
	je ___jump_if_0
	jmp ___jump_end_1
	___jump_if_0:
	; ASSIGN a = 0
	mov EAX, 0
	mov DWORD [ rsp + 0 ], EAX
	; ASSIGN a = 0
	mov EAX, 0
	mov DWORD [ rsp + 0 ], EAX
	___jump_end_1:
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 0 ]
	add rsp, 12
	ret
	
	
Start_262262:
	sub rsp, 16
	; ASSIGN b = add_262262
	; CALL FUNCTION add_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov  DWORD[rsp+4] , 0
	mov  DWORD[rsp+0] , 6
	add rsp, 16
	; parametri conclusi
	call add_262262
	mov EAX, EAX
	; ALLOCATION di bin posizione : 8
	mov DWORD [ rsp + 4 ], EAX
	; ASSIGN a = math_expression
	
	; MATH EXPRESSION
	
	mov ecx , 8
	mov eax , 7
	add eax, ecx
	mov EAX, eax
	; ALLOCATION di ain posizione : 12
	mov DWORD [ rsp + 0 ], EAX
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 4 ]
	add rsp, 16
	ret
	
	
