; programma.asm
; Compilare con: nasm -f win64 programmacopy.asm -o programma.obj
; Linkare con: GoLink /console kernel32.dll programma.obj

NULL              EQU 0
STD_OUTPUT_HANDLE EQU -11

extern GetStdHandle, ReadConsoleA
extern WriteFile
extern ExitProcess
extern GetProcessHeap
extern HeapAlloc
extern Start_262262


section .data
    inputBuffer db 128 dup(0)
    charsRead   dd 0
    StandardInput dq 0

section .bss
    
    StandardHandle resq 1
    Written        resq 1
    allocated_memory resq 1
    heap_handle    resq 1
    
section .text


global Start, print_unsigned_int, print_str, alloc, xor_allocazione, add_262262_262, input_func, input_to_string, string_to_int
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

input_func:
    mov  rcx, [rel StandardInput]             ; RCX = hConsoleInput
    mov  rdx, inputBuffer      ; RDX = pointer to our buffer
    mov  r8d, 128              ; R8D = number of chars to read (DWORD)
    mov  r9, charsRead         ; R9  = pointer to store numberOfCharsRead
    sub  rsp, 32               ; Reserve space for the 5th parameter and shadow
    xor  rax, rax              ; pReserved = NULL
    push rax
    call ReadConsoleA
    ADD  rsp, 40               ; Restore the stack
    ret 

input_to_string:    
    mov rdx, [charsRead]
    mov rax, rdx
    mov r14d , eax
    add rax, 4
    
    call alloc

    mov dword [rax], r14d
    mov rdx, rax
    add rax, 4
    xor rcx, rcx
    loop_input:
    
    mov bl, [inputBuffer + ecx]
    mov byte [rax  + rcx], bl
    inc rcx
    cmp ecx, r14d
    jne loop_input
    
    mov rax, rdx
    ret

; Function: string_to_int
; Purpose: Converts a null-terminated string in inputBuffer to an integer.
; Assumptions:
;   - inputBuffer points to the string.
;   - charsRead contains the number of characters read (including newline).
;   - The string represents a valid positive integer.

string_to_int:
    mov     r14d, [charsRead]      ; Load the number of characters read into r14d
    sub     r14d, 2                ; Adjust for newline and null terminator
    mov     rax, 0                 ; Initialize RAX to store the resulting integer
    mov     ecx, 0                 ; Initialize ECX as the loop counter/index

    loop_input_to_int:
        cmp     ecx, r14d              ; Compare current index with adjusted charsRead
        jge     end_loop                ; If index >= r14d, exit the loop

        movzx   rdx, byte [inputBuffer + rcx] ; Load the current character, zero-extend to RDX
        sub     rdx, '0'                ; Convert ASCII character to its numeric value
        imul    rax, rax, 10            ; Multiply current result by 10
        add     rax, rdx                 ; Add the numeric value of the current digit
        inc     rcx                      ; Move to the next character
        jmp     loop_input_to_int        ; Repeat the loop

    end_loop:
    ret                               ; Return with the result in RAX

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

    mov  ecx, -10              ; STD_INPUT_HANDLE = -10
    call GetStdHandle
    mov  [rel StandardInput], rax


    ; Get Process Heap Handle
    call  GetProcessHeap
    test  rax, rax                    ; Check if handle is valid
                  ; Exit if invalid
    mov   [heap_handle], rax          ; Save heap handle
    ; Allocate memory
    

        


	
	call Start_262262
    

	;add rsp, 16
    ;xor rax, rax
    
                       ; Exit code 0
    call  ExitProcess                 ; Exit the program

    
