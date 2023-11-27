INCLUDE Irvine32.inc
.data
	Sourcew WORD 10, 20, 30
	Targetw WORD 10, 20, 35
	WordArray WORD 10h, 20h, 30h, 40h
	CompareArrays PROTO, src:PTR WORD, trg:PTR WORD, sizeArr:DWORD
	SearchArray PROTO, src:PTR WORD, trg:WORD, sizeArr:DWORD
	samePrompt BYTE "Source Array and Target Array are the same", 0
	differentPrompt BYTE "Source Array and Target Array are NOT the same", 0
	searchBeforePrompt BYTE "Before searching, EDI is located at: ", 0
	searchPrompt BYTE "Searching for the matched word: ", 0
	searchSuccess BYTE "After searching, the matched word is located at: ", 0
	searchFail BYTE "Mo matched word is found", 0
.code
main PROC
	invoke CompareArrays, OFFSET Sourcew, OFFSET Targetw, LENGTHOF Sourcew
	invoke SearchArray, OFFSET WordArray, 30h, LENGTHOF Sourcew
	exit
main ENDP
CompareArrays PROC,
	src:PTR WORD, trg:PTR WORD, sizeArr:DWORD
	mov ecx, sizeArr
	mov esi, src
	mov edi, trg
	cld
	repe cmpsw
	jecxz arrSame
arrDiff:
	mov edx, OFFSET differentPrompt
	call WriteString
	call Crlf
	ret
arrSame:
	mov eax, 0
	mov ebx, 0
	mov ax, [esi - 2]
	mov bx, [edi - 2]
	cmp eax, ebx
	jne arrDiff
	mov edx, OFFSET samePrompt
	call WriteString
	call Crlf
	ret
CompareArrays ENDP

SearchArray PROC,
	src:PTR WORD, trg:WORD, sizeArr:DWORD
	mov edx, OFFSET searchBeforePrompt
	call WriteString
	mov eax, edi
	call WriteHex
	call Crlf
	mov edx, OFFSET searchPrompt
	call WriteString
	mov edi, src
	mov eax, DWORD PTR trg
	call WriteHex
	call Crlf
	mov ecx, sizeArr
	mov ax, trg
	cld
	repe scasw
	mov eax, edi
	mov edx, OFFSET searchSuccess
	call WriteString
	call WriteHex
	ret
notFound:
	mov edx, OFFSET searchFail
	call WriteString
	ret
SearchArray ENDP
END main
