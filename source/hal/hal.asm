[BIT 32]
HalFrom32ReturnTo16:
    jmp SelectorCode16:HalFrom32ReturnTo16_real
    HalFrom32ReturnTo16_real:
    mov ax, SelectorData16
    mov ds, ax
    mov es, ax


