INCLUDE Irvine32.inc
.data
	prompt1 byte "The output from the recursive call", 0
	prompt2 byte "The output from the loop call", 0
	Factorial PROTO, multiplier:DWORD
	Factorial_loop PROTO, multiplier:DWORD
.code
main PROC
mov edx, offset prompt1
	call WriteString
	call Crlf
	invoke Factorial, 10 ; calculate factorial (eax)
	call WriteDec ; display it
	call Crlf
	mov edx, offset prompt2
	call WriteString
	call Crlf
	invoke Factorial_loop, 10 ; calculate factorial (eax)
	call WriteDec ; display it
	call Crlf
exit
main ENDP
Factorial PROC,
	multiplier:DWORD
	mov eax, multiplier
	cmp eax, 1 ; n < 1? for the base case 1 and 0
	ja L1 ; yes: continue
	mov eax,1 ; no: return 1
	jmp L2
L1: dec eax
	push eax ; Factorial(n-1)
	call Factorial
	; Instructions from this point on execute when each
	; recursive call returns.
ReturnFact:
	mov ebx,multiplier ; get n
	mul ebx ; ax = ax * bx
L2:	
	ret
Factorial ENDP
Factorial_loop PROC,
	multiplier:DWORD
	mov ecx, multiplier ; get n
	mov eax, 1
L1: cmp ecx, 0 ; check if ecx == 0 then quit
	jz L2
	mul ecx ; otherwise multiple eax with ecx
	loop L1
L2: 
	ret
Factorial_loop ENDP
END main
