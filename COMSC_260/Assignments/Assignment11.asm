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
	mov inputSize, eax
	mov edx, OFFSET encryptPrompt
	call WriteString
	call EncodeString
	call DecodeString
	exit
main ENDP
EncodeString PROC
	pushad
	mov esi, OFFSET inputString
	mov ecx, 0
	mov edi, 0
startEncrypt:
	cmp ecx, inputSize
	jge finishEncrypt
	cmp edi, 10
	jl continueKey
	mov edi, 0
ContinueKey:	
	push ecx
	mov al, [esi + ecx]
	mov cl, key[edi]
	js Left
	ror al, cl
	jmp EditString
Left:
	neg cl
	rol al, cl
EditString:
	pop ecx
	mov [esi + ecx], al
	inc ecx
	inc edi
	jmp startEncrypt
finishEncrypt:
	;mov edx, OFFSET encryptPrompt
	;call WriteString
	mov edx, DWORD PTR OFFSET inputString
	call WriteString
	call Crlf
	popad
	ret
EncodeString ENDP

DecodeString PROC
	pushad
	mov esi, OFFSET inputString
	mov ecx, 0
	mov edi, 0
startEncrypt:
	cmp ecx, inputSize
	jge finishEncrypt
	cmp edi, 10
	jl continueKey
	mov edi, 0
ContinueKey:	
	push ecx
	mov al, [esi + ecx]
	mov cl, key[edi]
	js Right
	rol al, cl
	jmp EditString
Right:
	neg cl
	ror al, cl
EditString:
	pop ecx
	mov [esi + ecx], al
	inc ecx
	inc edi
	jmp startEncrypt
finishEncrypt:
	mov edx, OFFSET decryptPrompt
	call WriteString
	mov edx, OFFSET inputString
	call WriteString
	call Crlf
	popad
	ret
DecodeString ENDP

END main
