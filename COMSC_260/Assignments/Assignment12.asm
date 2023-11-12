INCLUDE Irvine32.inc

.data
packed_1a WORD 4536h
packed_1b WORD 7297h
sum DWORD ?

packed_2a DWORD 67345620h
packed_2b DWORD 54496342h
sum_2 DWORD 2 DUP(0)
DoubleWords2 = SIZEOF packed_2a / TYPE DWORD

packed_3a QWORD 6734562000346521h
packed_3b QWORD 5449634205738261h
sum_3 DWORD 3 DUP(0)

.code
main PROC
	mov esi, OFFSET packed_1a
	mov edi, OFFSET packed_1b
	mov edx, OFFSET sum
	mov ecx, SIZEOF packed_1a / TYPE BYTE
	call AddPacked
	mov eax, sum
	call WriteHex
	call Crlf
	mov esi, OFFSET packed_2a
	mov edi, OFFSET packed_2b
	mov edx, OFFSET sum_2
	mov ecx, SIZEOF packed_2a / TYPE BYTE
	call AddPacked
	mov ecx, SIZEOF packed_2a / TYPE WORD
	add edx, SIZEOF packed_2a
L2:
	mov eax, [edx]
	call WriteHex
	sub edx, TYPE DWORD
	loop L2
	call Crlf
	mov esi, OFFSET packed_3a
	mov edi, OFFSET packed_3b
	mov edx, OFFSET sum_3
	mov ecx, SIZEOF packed_3a / TYPE BYTE
	call AddPacked
	mov ecx, SIZEOF packed_3a / TYPE WORD - 1
	add edx, SIZEOF packed_3a
L3:
	mov eax, [edx]
	call WriteHex
	sub edx, TYPE DWORD
	loop L3
	exit
main ENDP
AddPacked PROC
	mov al, 0
	mov ah, 0
	mov ebx, 0
L1:
	mov al, [esi]
	adc al, [edi]
	add al, ah
	daa
	mov [edx + ebx], al
	inc esi
	inc edi
	inc ebx
	loop L1
	mov	al,0
	adc	al,0
	mov	BYTE PTR [edx + ebx],al
	ret
AddPacked ENDP
END main
