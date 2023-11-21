INCLUDE Irvine32.inc
.data
	Print_Board PROTO, color:BYTE
	Print_Row PROTO, color2:BYTE
	WriteColorBlock PROTO char:BYTE, backcolor:BYTE
.code
main PROC
	mov ecx, 16
L1:
	invoke Print_Board, cl
	mov eax, 500
	call Delay
	loop L1
	exit
main ENDP
Print_Board PROC,
	color:BYTE
	mov ecx, 8
L2:
	invoke Print_Row, color
	loop L2
	ret
Print_Board ENDP
Print_Row PROC,
	color2:BYTE
	mov ecx, 4
L3:
	invoke WriteColorBlock, 254, color2
	loop L3
	ret
Print_Row ENDP
WriteColorBlock PROC,
	char:BYTE, backColor:BYTE
	mov eax, DWORD PTR backColor
	call SetTextColor
	mov eax, DWORD PTR char
	call WriteChar
	ret
WriteColorBlock ENDP
END main
