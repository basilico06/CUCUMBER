	extern print_str, alloc, print_unsigned_int
section .text
global Start_262262, DllMain
DllMain:
	ret
AREA_QUADRATO_262262:
	sub rsp, 12
	; ASSIGN z = math_expression
	
	; MATH EXPRESSION
	
	mov ecx , DWORD [ rsp + 4 ]
	mov eax , DWORD [ rsp + 8 ]
	xor rdx, rdx
	mul ecx
	mov EAX, eax
	; ALLOCATION di zin posizione : 8
	mov DWORD [ rsp + 0 ], EAX
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 0 ]
	add rsp, 12
	ret
	
	
Start_262262:
	sub rsp, 20
	; ASSIGN h = 6
	mov EAX, 6
	; ALLOCATION di hin posizione : 8
	mov DWORD [ rsp + 8 ], EAX
	; ASSIGN l = 5
	mov EAX, 5
	; ALLOCATION di lin posizione : 12
	mov DWORD [ rsp + 4 ], EAX
	; ASSIGN res = AREA_QUADRATO_262262
	; CALL FUNCTION AREA_QUADRATO_262262
	mov rbx, rsp
	; paramether
	 mov rbx, rsp
	sub rsp, 16
	mov EAX, DWORD [ rsp + 20 ]
	mov  DWORD[rsp+4] , EAX
	mov EAX, DWORD [ rsp + 24 ]
	mov  DWORD[rsp+0] , EAX
	add rsp, 16
	; parametri conclusi
	call AREA_QUADRATO_262262
	mov EAX, EAX
	; ALLOCATION di resin posizione : 16
	mov DWORD [ rsp + 0 ], EAX
	mov rax , 33
	call alloc
	mov dword [rax] , 29
	mov byte [rax  + 4 + 0] ,116
	mov byte [rax  + 4 + 1] ,104
	mov byte [rax  + 4 + 2] ,101
	mov byte [rax  + 4 + 3] ,32
	mov byte [rax  + 4 + 4] ,98
	mov byte [rax  + 4 + 5] ,97
	mov byte [rax  + 4 + 6] ,115
	mov byte [rax  + 4 + 7] ,101
	mov byte [rax  + 4 + 8] ,32
	mov byte [rax  + 4 + 9] ,111
	mov byte [rax  + 4 + 10] ,102
	mov byte [rax  + 4 + 11] ,32
	mov byte [rax  + 4 + 12] ,116
	mov byte [rax  + 4 + 13] ,104
	mov byte [rax  + 4 + 14] ,101
	mov byte [rax  + 4 + 15] ,32
	mov byte [rax  + 4 + 16] ,114
	mov byte [rax  + 4 + 17] ,101
	mov byte [rax  + 4 + 18] ,99
	mov byte [rax  + 4 + 19] ,116
	mov byte [rax  + 4 + 20] ,97
	mov byte [rax  + 4 + 21] ,110
	mov byte [rax  + 4 + 22] ,103
	mov byte [rax  + 4 + 23] ,108
	mov byte [rax  + 4 + 24] ,101
	mov byte [rax  + 4 + 25] ,32
	mov byte [rax  + 4 + 26] ,105
	mov byte [rax  + 4 + 27] ,115
	mov byte [rax  + 4 + 28] ,32
	mov rax, rax
	mov rdx , rax
	add rdx, 4
	mov r8d , [rax]
	call print_str
	mov eax, DWORD [ rsp + 4 ]
	call print_unsigned_int
	mov rdx , rax
	mov r8d , 20
	call print_str
	mov rax , 24
	call alloc
	mov dword [rax] , 20
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 1] ,97
	mov byte [rax  + 4 + 2] ,110
	mov byte [rax  + 4 + 3] ,100
	mov byte [rax  + 4 + 4] ,32
	mov byte [rax  + 4 + 5] ,105
	mov byte [rax  + 4 + 6] ,116
	mov byte [rax  + 4 + 7] ,115
	mov byte [rax  + 4 + 8] ,32
	mov byte [rax  + 4 + 9] ,104
	mov byte [rax  + 4 + 10] ,101
	mov byte [rax  + 4 + 11] ,105
	mov byte [rax  + 4 + 12] ,103
	mov byte [rax  + 4 + 13] ,104
	mov byte [rax  + 4 + 14] ,116
	mov byte [rax  + 4 + 15] ,32
	mov byte [rax  + 4 + 16] ,105
	mov byte [rax  + 4 + 17] ,115
	mov byte [rax  + 4 + 18] ,32
	mov byte [rax  + 4 + 19] ,32
	mov rax, rax
	mov rdx , rax
	add rdx, 4
	mov r8d , [rax]
	call print_str
	mov eax, DWORD [ rsp + 8 ]
	call print_unsigned_int
	mov rdx , rax
	mov r8d , 20
	call print_str
	mov rax , 22
	call alloc
	mov dword [rax] , 18
	mov byte [rax  + 4 + 0] ,32
	mov byte [rax  + 4 + 1] ,32
	mov byte [rax  + 4 + 2] ,97
	mov byte [rax  + 4 + 3] ,110
	mov byte [rax  + 4 + 4] ,100
	mov byte [rax  + 4 + 5] ,32
	mov byte [rax  + 4 + 6] ,105
	mov byte [rax  + 4 + 7] ,116
	mov byte [rax  + 4 + 8] ,115
	mov byte [rax  + 4 + 9] ,32
	mov byte [rax  + 4 + 10] ,97
	mov byte [rax  + 4 + 11] ,114
	mov byte [rax  + 4 + 12] ,101
	mov byte [rax  + 4 + 13] ,97
	mov byte [rax  + 4 + 14] ,32
	mov byte [rax  + 4 + 15] ,105
	mov byte [rax  + 4 + 16] ,115
	mov byte [rax  + 4 + 17] ,32
	mov rax, rax
	mov rdx , rax
	add rdx, 4
	mov r8d , [rax]
	call print_str
	mov eax, DWORD [ rsp + 0 ]
	call print_unsigned_int
	mov rdx , rax
	mov r8d , 20
	call print_str
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 0 ]
	add rsp, 20
	ret
	
	
