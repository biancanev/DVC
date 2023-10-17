; Assignment 9
; Programmer Name: Ryan Kwong(1440216)

INCLUDE Irvine32.inc
ExitProcess PROTO, dwExitCode:dword

BUFMAX = 128
KEYMAX = 128

.data
sPrompt BYTE "Enter the plain text: ", 0
sKey BYTE "Enter the encryption key: ", 0
sEncrypt BYTE "Cipher text: ", 0
sDecrypt BYTE "Decrypted: ", 0
buffer BYTE BUFMAX + 1 DUP(0)
key BYTE BUFMAX + 1 DUP(0)
bufSize DWORD ?
keySize DWORD ?

.code
SetKey PROC
	pushad
	mov edx, OFFSET sKey
	call WriteString
	mov edx, OFFSET key
	mov ecx, KEYMAX
	call ReadString
	mov keySize, eax
	cmp bufSize, keySize
	jg Greater
	jl Less
Less:
	mov esi, OFFSET key
	mov ecx, keySize - bufSize
L3:
	mov [esi]
Greater:
	
	popad
	ret
SetKey ENDP

TranslateString PROC
	pushad
	mov ecx, bufSize
	mov edi, OFFSET key
L1:
	mov eax, [edi]
	xor dword ptr buffer[ecx], eax
	;key needs to repeat here, but idk how to
	loop L1
	mov edx, OFFSET buffer
	call WriteString
	popad
	ret
TranslateString ENDP

InputString PROC
	pushad
	mov edx, OFFSET sPrompt
	call WriteString
	mov ecx, BUFMAX
	mov edx, OFFSET buffer
	call ReadString
	mov bufSize, eax
	call Crlf
	popad
	ret
InputString ENDP

main PROC
	call InputString
	call SetKey
	mov edx, OFFSET sEncrypt
	call WriteString
	call TranslateString
	call Crlf
	mov edx, OFFSET sDecrypt
	call WriteString
	call TranslateString
	invoke ExitProcess,0
main ENDP
END main
