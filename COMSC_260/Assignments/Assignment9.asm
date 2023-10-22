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
	popad
	ret
SetKey ENDP

TranslateString PROC
	pushad
	mov ecx, bufSize
	mov edi, OFFSET key        
	mov esi, OFFSET buffer     
	mov ebx, 0              
L1:
	mov al, [edi + ebx]       
	xor byte ptr [esi], al     
	inc ebx                   
	cmp ebx, keySize               
	jge L2               
L2:
	inc esi
	mov ebx, 0
	loop L1 
	mov edx, OFFSET buffer
	call WriteString
	call Crlf
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
	call WaitMsg
	invoke ExitProcess,0
main ENDP
END main
