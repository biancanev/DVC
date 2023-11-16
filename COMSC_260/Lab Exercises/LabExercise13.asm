INCLUDE Irvine32.inc

.data
count = 25
darray DWORD count DUP(?)
header1 BYTE "ArrayFill1:", 0
header2 BYTE "ArrayFill2:", 0
header3 BYTE "ArrayFill3:", 0
.code
main PROC
	call Randomize
	push OFFSET darray
	push count
	call ArrayFill
	push OFFSET darray
	push count
	call ArrayFill2
	push OFFSET darray
	push count
	call ArrayFill3
	exit
main ENDP

BetterRandomRange PROC
	sub eax, ebx				;subtract eax from ebx for full range
	call RandomRange			;Call RandomRange
	add eax, ebx				;add back ebx to get value within range
	ret						;return procedure
BetterRandomRange ENDP

PrintArray PROC USES EBX ESI
    mov edx, ebx
    call WriteString
    call Crlf
L3:
    mov eax, [esi]
    call WriteInt
    call Crlf
    add esi, 4
    loop L3
    ret
PrintArray ENDP

ArrayFill PROC
	push ebp
	mov ebp, esp
	sub esp, 8
	mov DWORD PTR [esp + 4], 200		;upper
	mov DWORD PTR [esp + 8], -100		;lower
	mov ecx, [ebp + 8]
	mov esi, [ebp + 12]
L1:
	mov eax, [esp + 4]
	mov ebx, [esp + 8]
	call BetterRandomRange
	mov [esi], eax
	add esi, 4
	loop L1
	mov ecx, [ebp + 8]
	mov esi, [ebp + 12]
	mov ebx, OFFSET header1
	call PrintArray
	mov esp, ebp
	pop ebp
	ret 8
ArrayFill ENDP

ArrayFill2 PROC
	enter 8, 0
	sub esp, 8
	mov DWORD PTR [esp + 4], 200		;upper
	mov DWORD PTR [esp + 8], -100		;lower
	mov ecx, [ebp + 8]
	mov esi, [ebp + 12]
L2:
	mov eax, [esp + 4]
	mov ebx, [esp + 8]
	call BetterRandomRange
	mov [esi], eax
	add esi, 4
	loop L2
	mov ecx, [ebp + 8]
	mov esi, [ebp + 12]
	mov ebx, OFFSET header2
	call PrintArray
	leave
	ret 8
ArrayFill2 ENDP

ArrayFill3 PROC
	LOCAL upper:DWORD, lower:DWORD
	mov upper, 200
	mov lower, -100
	mov ecx, [ebp + 8]
	mov esi, [ebp + 12]
L3:
	mov eax, upper
	mov ebx, lower
	call BetterRandomRange
	mov [esi], eax
	add esi, 4
	loop L3
	mov ecx, [ebp + 8]
	mov esi, [ebp + 12]
	mov ebx, OFFSET header3
	call PrintArray
	ret 8
ArrayFill3 ENDP
END main
