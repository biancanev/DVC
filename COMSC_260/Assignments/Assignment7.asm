; Assignment 7
; Programmer Name: Ryan Kwong(1440216)

; //include Irvine32.inc

INCLUDE Irvine32.inc

.data
prompt1 byte "Please enter the lower bound: ", 0
prompt2 byte "Please enter the upper bound: ", 0
lowerBound dword ?
upperBound dword ?

.code

BetterRandomRange PROC
	mov eax, upperBound         ;set eax to the upperBound
	add eax, lowerBound         ;add the lowerBound to the eax
	call RandomRange            ;call rand integer procedure
	sub eax, lowerBound         ;subtract lowerBound from random int
BetterRandomRange ENDP

main PROC
	mov ecx, 3                  ;set loop counter to 3
L1:
	mov edx, OFFSET prompt1     ;prepare prompt1 for display
	call WriteString            ;display prompt1
	call ReadInt                ;get user input
	mov lowerBound, eax         ;store input in lowerBound variable
	mov edx, OFFSET prompt2     ;prepare prompt2 for display
	call WriteString            ;display prompt2
	call ReadInt                ;get user input
	mov upperBound, eax         ;store input in upperBound variable
	call BetterRandomRange      ;generate random number with new procedure
	call WriteInt               ;write the result
	loop L1                     ;loop

main ENDP

END main
