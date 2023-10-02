; Assignment 7
; Programmer Name: Ryan Kwong(1440216)

; //include Irvine32.inc

INCLUDE Irvine32.inc
ExitProcess PROTO, dwExitCode:dword

.data
prompt1 byte "Please enter the lower bound: ", 0
prompt2 byte "Please enter the upper bound: ", 0
count DWORD ?

.code

BetterRandomRange PROC
	add eax, ebx
	call RandomRange			;Call RandomRange
	neg ebx
	sub eax, ebx				
	ret
BetterRandomRange ENDP

main PROC

	mov ecx, 3
L1:
	mov count, ecx
	mov edx, OFFSET prompt1		;prepare prompt1 for display
	call WriteString			;display prompt1
	call ReadInt				;get user input
	mov ebx, eax				;move the lower bound to ebx
	mov edx, OFFSET prompt2		;prepare prompt2 for display
	call WriteString			;display prompt2
	call ReadInt				;get user input
	mov ecx, 30
L2:
	push eax					;store lower bound into stack
	push ebx					;store upper bound into stack
	call BetterRandomRange		;generate random number with new procedure
	call WriteInt				;write the result
	call Crlf					;Line break
	pop eax					;restore eax
	pop ebx					;restore ebx
	loop L2

	mov ecx, count
	loop L1

	invoke ExitProcess,0
main ENDP

END main
