INCLUDE Irvine32.inc
.data
	Print_Board PROTO, color:BYTE, index:BYTE
	Print_Row PROTO, color2:BYTE, index:BYTE
	WriteColorBlock PROTO char:BYTE, backcolor:BYTE, index:BYTE, index2:BYTE
.code
main PROC
	mov ecx, 16
L1:
	mov edx, 0
	call GotoXY
	invoke Print_Board, cl, cl
	mov eax, 500
	call Delay
	loop L1
	mov eax, 7
	call SetTextColor
	exit
main ENDP
Print_Board PROC,
	color:BYTE, index:BYTE
	mov ecx, 8
L2:
	invoke Print_Row, color, cl
	call Crlf
	loop L2
	mov cl, index
	ret
Print_Board ENDP
Print_Row PROC,
	color2:BYTE, index:BYTE
	push ecx
	mov ecx, 4
L3:
	invoke WriteColorBlock, 32, color2, cl, index
	loop L3
	mov ecx, DWORD PTR index
	ret
Print_Row ENDP
WriteColorBlock PROC,
	char:BYTE, backColor:BYTE, index:BYTE, index2:BYTE
	test index2, 1
	jnz L4
	movzx eax, backColor
	shl eax, 4
	call SetTextColor
	mov eax, DWORD PTR char
	call WriteChar
	call WriteChar
	mov eax, white*16
	call SetTextColor
	mov eax, DWORD PTR char
	call WriteChar
	call WriteChar
	jmp Final
L4:
	mov eax, white*16
	call SetTextColor
	mov eax, DWORD PTR char
	call WriteChar
	call WriteChar
	movzx eax, backColor
	shl eax, 4
	call SetTextColor
	mov eax, DWORD PTR char
	call WriteChar
	call WriteChar
Final:
	mov ecx, DWORD PTR index
	ret
WriteColorBlock ENDP
END main
