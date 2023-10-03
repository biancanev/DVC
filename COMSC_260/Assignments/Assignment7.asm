; Assignment 7
; Programmer Name: Ryan Kwong(1440216)

INCLUDE Irvine32.inc
ExitProcess PROTO, dwExitCode:dword

.data
prompt1 byte "Please enter the lower bound: ", 0	;lower bound prompt
prompt2 byte "Please enter the upper bound: ", 0	;upper bound prompt
count DWORD ?								;For nested loops

.code

BetterRandomRange PROC
	sub eax, ebx				;subtract eax from ebx for full range
	call RandomRange			;Call RandomRange
	add eax, ebx				;add back ebx to get value within range
	ret						;return procedure
BetterRandomRange ENDP

main PROC

	mov ecx, 3				;outer nested loop counter
L1:
	mov count, ecx				;store outer counter
	mov edx, OFFSET prompt1		;prepare prompt1 for display
	call WriteString			;display prompt1
	call ReadInt				;get user input
	mov ebx, eax				;move the lower bound to ebx
	mov edx, OFFSET prompt2		;prepare prompt2 for display
	call WriteString			;display prompt2
	call ReadInt				;get user input
	mov ecx, 30				;inner nested loop counter
L2:
	push eax					;store lower bound into stack
	push ebx					;store upper bound into stack
	call BetterRandomRange		;generate random number with new procedure
	call WriteInt				;write the result
	call Crlf					;Line break
	pop ebx					;restore ebx
	pop eax					;restore eax
	loop L2					;loop inner

	mov ecx, count				;restore outer loop counter
	loop L1					;loop outer

	invoke ExitProcess,0		;end program
main ENDP

END main
