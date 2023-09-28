; Reversing an Array(Assignment6.asm)

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:dword

.data
	arrayD dword 100, 200, 250, 300, 500, 600, 700, 900, 1000, 1200, 2000, 3000
.code
main proc
	;Part 1 - Indexed addressing swap
	mov ecx, LENGTHOF arrayD / 2; loop counter
	mov ebx, LENGTHOF arrayD - 1
	mov eax, 0
L1:	
	mov esi, dword ptr arrayD[ebx * TYPE arrayD]
	mov edi, dword ptr arrayD[eax * TYPE arrayD]
	xchg esi, edi
	mov dword ptr arrayD[ebx * TYPE arrayD], esi
	mov dword ptr arrayD[eax * TYPE arrayD], edi
	dec ebx
	inc eax
	loop L1

	;Part 2 - Indirect address swap
	mov esi, OFFSET arrayD
	mov edi, OFFSET arrayD + (LENGTHOF arrayD - 1) * TYPE arrayD
	mov ecx, LENGTHOF arrayD / 2
L2:
	mov eax, [esi]
	xchg eax, [edi]
	mov [esi], eax
	add esi, TYPE esi
	sub edi, TYPE edi
	loop L2

	invoke ExitProcess,0
main endp
end main
