INCLUDE Irvine32.inc
.data
	target BYTE "01ABAAAAAABABCC45ABC9012", 0
	source BYTE "AAABA", 0
	Str_find PROTO, pTarget:PTR BYTE, pSource:PTR BYTE, sizeTrg:DWORD, sizeSrc:DWORD
	notFound BYTE "Target String is not found", 0
	foundString BYTE "Source string found at position ", 0
	foundString2 BYTE " in Target string (counting from 0)", 0
	TargetPrompt BYTE "The target string is: ", 0
	SourcePrompt BYTE "The source string is: ", 0
	pos DWORD ?
.code
main PROC
	mov edx, OFFSET TargetPrompt
	call WriteString
	mov edx, OFFSET target
	call WriteString
	call Crlf
	call StrLength
	mov ebx, eax
	mov edx, OFFSET SourcePrompt
	call WriteString
	mov edx, OFFSET source
	call WriteString
	call Crlf
	call StrLength
	invoke Str_find, ADDR target, ADDR source, ebx, eax
	exit
main ENDP
Str_find PROC,
	pTarget:PTR BYTE, pSource:PTR BYTE, sizeTrg:DWORD, sizeSrc:DWORD
	pushad
	mov esi, DWORD PTR pTarget
	mov edi, DWORD PTR pSource
	mov ecx, sizeTrg
	mov ebx, 0
L1:
	mov al, [esi]
	mov dl, [edi]
	cmp al, dl
	je FirstMatch
	inc esi
	inc ebx
	loop L1
	jmp StrDiff
FirstMatch:
	push ecx
	mov ecx, sizeSrc
	push esi
	cld
	repe cmpsb
	jecxz StrMatch
StrDiff:
	cmp ecx, 0
	jne Restore
	mov edx, OFFSET notFound
	call WriteString
	popad
	ret
StrMatch:
	mov edx, OFFSET FoundString
	call WriteString
	mov eax, ebx
	call WriteDec
	mov edx, OFFSET FoundString2
	call WriteString
	ret
Restore:
	pop esi
	pop ecx
	inc esi
	inc ebx
	mov edi, DWORD PTR pSource
	jmp L1
Str_find ENDP
END main
