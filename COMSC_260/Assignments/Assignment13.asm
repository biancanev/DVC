INCLUDE Irvine32.inc

.data
	text1 BYTE "The greatest common divisor between ", 0
	and1 BYTE " and ", 0
	is1 BYTE " is: ", 0
	op1 DWORD ?
	op2 DWORD ?
.code
main PROC
	mov op1, 35
	mov op2, 15
	push op1
	push op2
	call Print
	call Euclidean
	mov eax, ebx
	call WriteDec
	call Crlf

	mov op1, 72
	mov op2, 18
	push op1
	push op2
	call Print
	call Euclidean
	mov eax, ebx
	call WriteDec
	call Crlf

	mov op1, 31
	mov op2, 17
	push op1
	push op2
	call Print
	call Euclidean
	mov eax, ebx
	call WriteDec
	call Crlf

	mov op1, 128
	mov op2, 640
	push op1
	push op2
	call Print
	call Euclidean
	mov eax, ebx
	call WriteDec
	call Crlf

	mov op1, 121
	mov op2, 0
	push op1
	push op2
	call Print
	call Euclidean
	mov eax, ebx
	call WriteDec
	call Crlf
	exit
main ENDP

Euclidean PROC USES EAX
	enter 8, 0
	mov eax, [ebp + 16]
	mov ebx, [ebp + 12]
	cmp eax, ebx
	jge IsZero
	xchg eax, ebx
IsZero:
	cmp ebx, 0
	je Replace
	mov edx, 0
	mov ecx, ebx
	div ecx
	cmp edx, 0
	je Final
	push ebx
	push edx
	call Euclidean
	jmp Final
Replace:
	xchg eax, ebx
Final:
	leave
	ret 8
Euclidean ENDP

Print PROC
	mov edx, OFFSET text1
	call WriteString
	mov eax, op1
	call WriteDec
	mov edx, OFFSET and1
	call WriteString
	mov eax, op2
	call WriteDec
	mov edx, OFFSET is1
	call WriteString
	ret
Print ENDP
END main
