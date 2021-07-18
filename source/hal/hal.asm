org 0x7000

[BITS 32]
HalFrom32ReturnTo16:
	cli
    jmp SelectorCode16:HalFrom32ReturnTo16_32
    HalFrom32ReturnTo16_32:
    mov eax, SelectorData16
    mov ds, eax
    mov es, eax

	mov eax, cr0
	and al, 1111_1110b
	mov cr0, eax
	jmp 0:HalFrom32ReturnTo16_16

	[BITS 16]
	HalFrom32ReturnTo16_16:
	mov ax, cs
	mov ds, ax
	mov es, ax
	mov ss, ax

	pop dx
	pop bp
	add sp, 4
	sti
	jmp bp:dx


HalFrom16ReturnTo32:
	cli
	mov eax, cr0
	or eax, 1
	mov cr0, eax

	jmp SelectorCode32:HalFrom16ReturnTo32_32
	[BITS 32]
	HalFrom16ReturnTo32_32:
	mov eax, SelectorData32
	mov ds, eax
	mov es, eax
	mov ss, eax

	pop edx
	sti
	jmp edx
