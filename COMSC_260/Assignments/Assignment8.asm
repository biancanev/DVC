; Assignment 8
; Programmer Name: Ryan Kwong(1440216)

INCLUDE Irvine32.inc
ExitProcess PROTO, dwExitCode:dword

.data
tempString BYTE 100 DUP(0)
.code

CreateRandomString PROC USES eax esi
	mov ecx, eax				;set loop counter to random generated length L
L2:
							;characters range from A(65) to Z(90)
	mov eax, 25				;set the range to 25(will add 65 later for full char range)
	call RandomRange			;get random integer that represents a character
	add eax, 65				;add 65 to get correct range
	mov [esi], al				;set the value of the address esi is pointing to
	inc esi					;increment esi to get next string char
	loop L2					;loop
	mov byte ptr [esi], 0		;null terminate the string
	ret
CreateRandomString ENDP

main PROC
	call Randomize				;set new random seed
	mov ecx, 20				;set loop counter to 20
L1:
	mov eax, 99				;set range to 99(will add 1 later, cannot generate a length of 0)
	call RandomRange			;generate random length
	add eax, 1				;add 1 to get the full 100 char range
	mov esi, OFFSET tempString	;set esi to address of string
	push ecx					;push the loop counter. will use a nested loop
	call CreateRandomString		;call the randomstring procedure
	pop ecx					;return original counter
	mov edx, esi				;load the string into edx
	call WriteString			;write the string to the console
	call Crlf					;carriage return
	loop L1					;loop
	invoke ExitProcess,0		;end program
main ENDP
END main
