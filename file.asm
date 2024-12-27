; programma.asm
; Compilare con: nasm -f win64 programmacopy.asm -o programma.obj
; Linkare con: GoLink /console kernel32.dll programma.obj

NULL              EQU 0
STD_OUTPUT_HANDLE EQU -11

extern GetStdHandle
extern WriteFile
extern ExitProcess
extern GetProcessHeap
extern HeapAlloc

extern Start_262262

section .bss

    StandardHandle resq 1
    Written        resq 1
    allocated_memory resq 1
    heap_handle    resq 1
    
section .text

global Start
alloc:
    sub  RSP, 32                         ; Shadow space
    mov   rcx, [heap_handle]              ; 1° parametro: Handle dell'heap
    mov   rdx, rax               ; 2° parametro: Dimensione dell'allocazione (64 byte)
    xor   r8, r8                          ; 3° parametro: Flag (0 per NULL)
    call  HeapAlloc                       ; Chiama HeapAlloc
    add   RSP, 32                         ; Ripristina lo stack
    ret


xor_allocazione:
    ;input  rax -> pointer to the block
    ;       rdx -> size of the block
    sub RSP, 32
    add rdx, rax 
    mov r10b, 0
    loop_xor:
    mov [rax], r10b
    inc rax
    cmp rax, rdx
    jne loop_xor
    add rsp, 32
    ret            

print_unsigned_int:
    ; input: rax -> unsigned int to print
    sub   rsp, 32                      ; Allocate shadow space
    mov   ebx, eax                     ; Save the input number
    mov   rax, 21                      ; Allocate 20 bytes (max digits for 64-bit integer)
    call  alloc                        ; Call alloc to get memory
    
    mov   r15, rax                     ; Save the allocated pointer
    mov   rdx, 20
    call xor_allocazione
    mov   rax, r15                     ; Restore the allocated pointer
    add   rax, 19                      ; Point to the end of the buffer (for writing digits backwards)
    mov   byte [rax+1], 0                ; Null-terminate the string
    mov   rcx, rax                     ; Pointer for writing digits

    mov   eax, ebx                     ; Load the original number into eax
    mov   r8d, 10                      ; Base 10
    xor   r9d, r9d                     ; Initialize digit counter

    conversion_loop_print_unsigned_int:
    xor   edx, edx                     ; Clear edx for division
    div   r8d                          ; Divide: rax = rax / 10, rdx = remainder
    add   dl, '0'                      ; Convert remainder to ASCII
    dec   rcx                          ; Move backwards in the buffer
    mov   [rcx], dl                    ; Store the ASCII digit
    inc   r9d                          ; Increment digit counter
    cmp   eax, 0                       ; Check if we're done
    jne   conversion_loop_print_unsigned_int

    mov   rax, r15                     ; Restore the allocated pointer
    mov   rdx, r9                      ; Set rdx to the string length (digit count)

    ;ret qui e il problena
    add   rsp, 32                      ; Restore the stack
    ret




print_str:
    ; input 
    ;rdx -> pointer to string
    ;r8 -> length of string
    sub   RSP, 32 + 8 + 8                       ; Shadow space + 5th parameter + align stack
                                                ; to a multiple of 16 bytes
    mov   RCX, qword [REL StandardHandle]                       
    lea   R9, [REL Written]                        ; 4th parameter
    mov   qword [RSP + 4 * 8], NULL                ; 5th parameter
    call  WriteFile                                ; Output can be redirect to a file using >
    add   RSP, 48                                  ; Remove the 48 bytes
    ret

add_262262_262:
    sub RSP, 32
    sub RSP, 16 
    mov qword [rsp +8], rax
    mov qword [rsp +0], rbx
    add eax, ebx
    add rsp, 48
    ret

Start:
    sub   rsp, 8                      ; Align stack to 16 bytes

    ; Get Standard Output Handle
    sub   rsp, 32                     ; Shadow space
    mov   ecx, STD_OUTPUT_HANDLE      ; Parameter: STD_OUTPUT_HANDLE
    call  GetStdHandle               ; Exit if invalid
    mov   [rel StandardHandle], rax   ; Save handle
    add   rsp, 32                     ; Restore stack

    ; Get Process Heap Handle
    call  GetProcessHeap
    test  rax, rax                    ; Check if handle is valid
                  ; Exit if invalid
    mov   [heap_handle], rax          ; Save heap handle
    ; Allocate memory
    

        
	; CALL FUNCTION Start_262262
	


	call Start_262262


                      ; Save the return value
    call print_unsigned_int
    mov   rdx, rax
    mov r8, 20                    ; Length of string
    call  print_str

	add rsp, 16

    
    xor  ecx, ecx                    ; Exit code 0
    call  ExitProcess                 ; Exit the program

    
