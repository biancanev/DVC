; Lab Exercise 8
; Programmer Name: Ryan Kwong(1440216)

INCLUDE Irvine32.inc
ExitProcess PROTO, dwExitCode:dword

.data
prompt1 byte "Enter first integer: ", 0
prompt2 byte "Enter second integer: ", 0
prompt3 byte "The sum is: ", 0

.code

main PROC
	mov ecx, 3
L1:
	call Randomize
	mov eax, 256
	call RandomRange
	call SetTextColor
	call Clrscr 
	call GetMaxXY
	mov dl, 40
	mov dh, 10
	call Gotoxy
	mov edx, OFFSET prompt1
	call WriteString
	call ReadInt
	mov dl, 40
	mov dh, 11
	call Gotoxy
	mov ebx, eax
	mov edx, OFFSET prompt2
	call WriteString
	call ReadInt
	mov dl, 40
	mov dh, 12
	call Gotoxy
	add eax, ebx
	mov edx, OFFSET prompt3
	call WriteString
	call WriteInt
	call Crlf
	call WaitMsg
	loop L1
	invoke ExitProcess,0		;end program
main ENDP

END main
