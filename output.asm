	extern print_str, alloc, print_unsigned_int, input_func, input_to_string, string_to_int
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
	; ALLOCATION di hin posizione : 8
	; ALLOCATION di lin posizione : 12
	mov rax , 36
	call alloc
	mov dword [rax] , 33
	mov byte [rax  + 4 + 0] ,73
	mov byte [rax  + 4 + 1] ,110
	mov byte [rax  + 4 + 2] ,115
	mov byte [rax  + 4 + 3] ,101
	mov byte [rax  + 4 + 4] ,114
	mov byte [rax  + 4 + 5] ,116
	mov byte [rax  + 4 + 6] ,32
	mov byte [rax  + 4 + 7] ,116
	mov byte [rax  + 4 + 8] ,104
	mov byte [rax  + 4 + 9] ,101
	mov byte [rax  + 4 + 10] ,32
	mov byte [rax  + 4 + 11] ,98
	mov byte [rax  + 4 + 12] ,97
	mov byte [rax  + 4 + 13] ,115
	mov byte [rax  + 4 + 14] ,101
	mov byte [rax  + 4 + 15] ,32
	mov byte [rax  + 4 + 16] ,111
	mov byte [rax  + 4 + 17] ,102
	mov byte [rax  + 4 + 18] ,32
	mov byte [rax  + 4 + 19] ,116
	mov byte [rax  + 4 + 20] ,104
	mov byte [rax  + 4 + 21] ,101
	mov byte [rax  + 4 + 22] ,32
	mov byte [rax  + 4 + 23] ,114
	mov byte [rax  + 4 + 24] ,101
	mov byte [rax  + 4 + 25] ,99
	mov byte [rax  + 4 + 26] ,116
	mov byte [rax  + 4 + 27] ,97
	mov byte [rax  + 4 + 28] ,110
	mov byte [rax  + 4 + 29] ,103
	mov byte [rax  + 4 + 30] ,108
	mov byte [rax  + 4 + 31] ,101
	mov byte [rax  + 4 + 33] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , [rax]
	call print_str
	; INPUT STATMENT
	call input_func
	call string_to_int
	mov DWORD [ rsp + 8 ], eax
	mov rax , 38
	call alloc
	mov dword [rax] , 35
	mov byte [rax  + 4 + 0] ,73
	mov byte [rax  + 4 + 1] ,110
	mov byte [rax  + 4 + 2] ,115
	mov byte [rax  + 4 + 3] ,101
	mov byte [rax  + 4 + 4] ,114
	mov byte [rax  + 4 + 5] ,116
	mov byte [rax  + 4 + 6] ,32
	mov byte [rax  + 4 + 7] ,116
	mov byte [rax  + 4 + 8] ,104
	mov byte [rax  + 4 + 9] ,101
	mov byte [rax  + 4 + 10] ,32
	mov byte [rax  + 4 + 11] ,104
	mov byte [rax  + 4 + 12] ,101
	mov byte [rax  + 4 + 13] ,105
	mov byte [rax  + 4 + 14] ,103
	mov byte [rax  + 4 + 15] ,104
	mov byte [rax  + 4 + 16] ,116
	mov byte [rax  + 4 + 17] ,32
	mov byte [rax  + 4 + 18] ,111
	mov byte [rax  + 4 + 19] ,102
	mov byte [rax  + 4 + 20] ,32
	mov byte [rax  + 4 + 21] ,116
	mov byte [rax  + 4 + 22] ,104
	mov byte [rax  + 4 + 23] ,101
	mov byte [rax  + 4 + 24] ,32
	mov byte [rax  + 4 + 25] ,114
	mov byte [rax  + 4 + 26] ,101
	mov byte [rax  + 4 + 27] ,99
	mov byte [rax  + 4 + 28] ,116
	mov byte [rax  + 4 + 29] ,97
	mov byte [rax  + 4 + 30] ,110
	mov byte [rax  + 4 + 31] ,103
	mov byte [rax  + 4 + 32] ,108
	mov byte [rax  + 4 + 33] ,101
	mov byte [rax  + 4 + 35] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , [rax]
	call print_str
	; INPUT STATMENT
	call input_func
	call string_to_int
	mov DWORD [ rsp + 4 ], eax
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
	mov rax , 30
	call alloc
	mov dword [rax] , 27
	mov byte [rax  + 4 + 0] ,116
	mov byte [rax  + 4 + 1] ,104
	mov byte [rax  + 4 + 2] ,101
	mov byte [rax  + 4 + 3] ,32
	mov byte [rax  + 4 + 4] ,97
	mov byte [rax  + 4 + 5] ,114
	mov byte [rax  + 4 + 6] ,101
	mov byte [rax  + 4 + 7] ,97
	mov byte [rax  + 4 + 8] ,32
	mov byte [rax  + 4 + 9] ,111
	mov byte [rax  + 4 + 10] ,102
	mov byte [rax  + 4 + 11] ,32
	mov byte [rax  + 4 + 12] ,116
	mov byte [rax  + 4 + 13] ,104
	mov byte [rax  + 4 + 14] ,101
	mov byte [rax  + 4 + 15] ,32
	mov byte [rax  + 4 + 16] ,115
	mov byte [rax  + 4 + 17] ,113
	mov byte [rax  + 4 + 18] ,117
	mov byte [rax  + 4 + 19] ,97
	mov byte [rax  + 4 + 20] ,114
	mov byte [rax  + 4 + 21] ,101
	mov byte [rax  + 4 + 22] ,32
	mov byte [rax  + 4 + 23] ,105
	mov byte [rax  + 4 + 24] ,115
	mov byte [rax  + 4 + 25] ,32
	mov byte [rax  + 4 + 27] , 0
	mov rax, rax
	xor r8, r8
	mov rdx , rax
	add rdx, 4
	mov r8d , [rax]
	call print_str
	xor rax, rax
	mov eax, DWORD [ rsp + 0 ]
	xor r8, r8
	call print_unsigned_int
	mov rdx , rax
	mov r8 , 21
	call print_str
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 0 ]
	add rsp, 20
	ret
	
	
