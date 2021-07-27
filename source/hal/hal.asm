org 0x7000

[BITS 32]
HalFrom32ReturnTo16:
	cli
	jmp 24:HalFrom32ReturnTo16_32
	HalFrom32ReturnTo16_32:
	mov eax, 32
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

	mov bx, sp
	add sp, 4
	sti
	jmp dword [bx]

[BITS 16]
HalFrom16ReturnTo32:
	cli
	mov eax, cr0
	or eax, 1
	mov cr0, eax

	jmp 8:HalFrom16ReturnTo32_32
	[BITS 32]
	HalFrom16ReturnTo32_32:
	mov eax, 16
	mov ds, eax
	mov es, eax
	mov ss, eax

	pop edx
	sti
	jmp edx

[BITS 16]
HalReadDiskSectorsWith13h:;byte driveNum,word num,dword buffer,qword startLBA
	mov ax, 0
	mov ds, ax
	mov di, sp
	sub sp, 10h

	mov byte [di - 1], 10h
	
	mov byte [di - 2], 0
	
	mov word ax, [di + 12]
	mov word [di - 4], ax
	
	mov word ax, [di + 8]
	mov word [di - 8], ax
	mov word ax, [di + 10]
	mov word [di - 6], ax

	mov word ax, [di]
	mov word [di - 16], ax
	mov word ax, [di + 2]
	mov word [di - 14], ax
	mov word ax, [di + 4]
	mov word [di - 12], ax
	mov word ax, [di + 6]
	mov word [di - 10], ax

	mov dl, [di + 14]

	dec di
	mov si, di

	mov ah, 42h
	int 13h
	ret 10h

[BITS 16]
HalWriteDiskSectorsWith13h:;byte driveNum,word num,dword buffer,qword startLBA
	mov ax, 0
	mov ds, ax
	mov di, sp
	sub sp, 10h

	mov byte [di - 1], 10h
	
	mov byte [di - 2], 0
	
	mov word ax, [di + 12]
	mov word [di - 4], ax
	
	mov word ax, [di + 8]
	mov word [di - 8], ax
	mov word ax, [di + 10]
	mov word [di - 6], ax

	mov word ax, [di]
	mov word [di - 16], ax
	mov word ax, [di + 2]
	mov word [di - 14], ax
	mov word ax, [di + 4]
	mov word [di - 12], ax
	mov word ax, [di + 6]
	mov word [di - 10], ax

	mov dl, [di + 14]

	dec di
	mov si, di

	mov ah, 43h
	mov al, 0
	int 13h
	ret 10h

