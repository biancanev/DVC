; Lab Exercise 7
; Programmer Name: Ryan Kwong(1440216)

INCLUDE Irvine32.inc

.data
buffer BYTE 51 DUP(0)			;create empty buffer of 51 bytes
byteCount DWORD ?				;variable for byte count of input

.code
main PROC
	mov edx, OFFSET buffer		;point to location of the buffer
	mov ecx, SIZEOF buffer		;get the size of the buffer
	call ReadString			;read the string inputted by user
	mov byteCount, eax			;save the number of char

	mov ecx, byteCount			;set loop counter to number of char
	mov esi, edx				;have stack index point to buffer
	call WriteString			;display original string
	call Crlf					;Line break
L1:
	mov eax, [esi]				;move the value of the buffer[esi] into eax
	push eax					;push value of eax into the stack
	inc esi					;increment the esi pointer
	loop L1					;loop

	;get string from the stack
	mov ecx, byteCount			;reset the loop counter to number of char
	mov esi, edx				;set the pointer back to location of buffer
L2:
	pop eax					;pop stack value to eax
	mov [esi], al				;rewrite the char at buffer[esi] to popped value
	inc esi					;increment the esi pointer
	loop L2					;loop

	call WriteString			;write string
	
	exit
main ENDP

END main
