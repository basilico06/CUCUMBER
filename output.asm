section .text
global Start_262262, DllMain
DllMain:
	ret
add_262262:
	sub rsp, 16
	; ASSIGN c = math_expression
	
	; MATH EXPRESSION
	
	mov ecx , DWORD [ rsp + 8 ]
	mov eax , DWORD [ rsp + 12 ]
	add eax, ecx
	mov EAX, eax
	; ALLOCATION di cin posizione : 8
	mov DWORD [ rsp + 4 ], EAX
	; ALLOCATION di din posizione : 12
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 4 ]
	add rsp, 16
	ret
	
	
Start_262262:
	sub rsp, 16
	; ASSIGN b = add_262262
	; CALL FUNCTION add_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov  DWORD[rsp+4] , 5
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
	
	
