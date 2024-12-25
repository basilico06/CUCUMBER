

section .text
global Start_262262, DllMain

Start_262262:
	sub rsp, 12
	; ASSIGN a = math_expression
	
	; MATH EXPRESSION
	mov eax , DWORD [ rsp + 8 ]
	mov ecx , DWORD [ rsp + 4 ]
	sub eax, ecx
	mov EAX, eax
	; ALLOCATION di ain posizione : 8
	mov DWORD [ rsp + 0 ], EAX
	; return statment -> mette in una derivazione di eax 
	mov EAX, DWORD [ rsp + 0 ]
	add rsp, 12
	ret