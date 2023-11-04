INCLUDE Irvine32.inc

MAXCHAR = 128

.data
	inputString BYTE MAXCHAR DUP(0), 0
	inputSize DWORD ?
	inputPrompt BYTE "Enter the plain text string: ", 0
	encryptPrompt BYTE "The encrypted text: ", 0
	decryptPrompt BYTE "The decrypted text: ", 0
	key BYTE -5, 3, 2, -3, 0, 5, 2, -4, 7, 9
.code
main PROC
	mov edx, OFFSET inputPrompt
	call WriteString
	mov ecx, MAXCHAR
	mov edx, OFFSET inputString
	call ReadString
	mov edx, OFFSET encryptPrompt
	call WriteString
	call EncodeString
	call DecodeString
	exit
main ENDP
EncodeString PROC
	pushad
	mov esi, OFFSET inputString
Beginning:
	mov ecx, 10
	mov eax, 0
L1:
	mov ebx, DWORD PTR key[eax]
	test ebx, ebx
	js Negative
	push ecx
	mov cl, key[eax]
	ror esi, cl
	inc esi
	inc eax
	pop ecx
	loop L1
Negative:
	push ecx
	mov ecx, DWORD PTR key[eax]
	shl ecx, TYPE DWORD
	xor ecx, DWORD PTR key[eax]
	rol esi, cl
	inc esi
	inc eax
	pop ecx
	loop L1
	cmp esi, OFFSET inputString + LENGTHOF input	String
	jg EndEncrypt
	jmp Beginning
EndEncrypt:
	mov edx, OFFSET inputString
	call WriteString
	call Crlf
	popad
	ret
EncodeString ENDP

DecodeString PROC
	pushad
	popad
	ret
DecodeString ENDP

END main
