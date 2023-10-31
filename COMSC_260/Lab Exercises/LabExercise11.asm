INCLUDE Irvine32.inc
.data
	hexArray DWORD 4BC94530h, 2CBA9429h, 4FB54386h, 69FC0544h, 5F5BE7ACh
	prompt BYTE "Enter the number of bits to shift to the left using SHLD: ", 0
.code
main PROC
	mov edx, OFFSET prompt
	call WriteString
	call ReadDec
	call shiftLeft
	mov esi, OFFSET hexArray
	mov ecx, LENGTHOF hexArray
	mov ebx, TYPE hexArray
	call DumpMem
	exit
main ENDP
shiftLeft PROC
	mov ebx, eax
	mov esi, OFFSET hexArray + (LENGTHOF hexArray - 1) * TYPE DWORD
	mov cl, bl
	shl DWORD PTR [esi], cl 
	sub esi, TYPE DWORD
	mov ecx, (LENGTHOF hexArray) - 1
L1:	
	push ecx
	mov eax, [esi + TYPE DWORD]
	mov cl, bl
	shld [esi], eax, cl
           	sub esi, TYPE DWORD
	pop ecx
	loop L1
	ret
	mov ecx, (LENGTHOF hexArray) - 1
shiftLeft ENDP
END main
