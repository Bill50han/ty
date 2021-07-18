[BITS 16]
org 0x8000
jmp mainStart

%include "GDT.inc"

;nop
;nop
;
;multibootHead:
;    dd 0x1BADB002
;    dd 0x00000001 | 0x00010000 | 0x00000004 
;    dd -(0x00000001 | 0x00010000 | 0x00000004  + 0x1BADB002)
;
;    dd multibootHead
;    dd _start
;    dd 0
;    dd 0
;    dd mainStart
;
;    dd 0
;    dd 1440
;    dd 900
;    dd 32
;
mainStart:

cli

mov ax, 0
mov ds, ax
mov es, ax

cld
mov cx, GDT_end - GDT_start - 1
mov si, GDT_start
mov di, 0x5000
rep movsb

db 0x66
lgdt [GDT_PTR]

in al, 92h
or al, 10b
out 92h, al

mov eax, cr0
or eax, 1
mov cr0, eax



GDT_start:
    newGDT_DATAorCODE GDT_NULL
    newGDT_DATAorCODE GDT_start, SelectorCode32, 0xFFFF, 0x0, 0x0, GDT_TYPE_DATAorCODE(GDT_TYPE_DATAorCODE_X_CODE, GDT_TYPE_DATAorCODE_C_1, GDT_TYPE_DATAorCODE_R_READABLE, GDT_TYPE_DATAorCODE_A), GDT_S_DATAorCODE, GDT_DPL_ring0, GDT_P_REAL, 0xF, GDT_AVL, GDT_L_0, GDT_DB_32, GDT_G_4KB, 0x0
    newGDT_DATAorCODE GDT_start, SelectorDate32, 0xFFFF, 0x0, 0x0, GDT_TYPE_DATAorCODE(GDT_TYPE_DATAorCODE_X_DATA, GDT_TYPE_DATAorCODE_E_TOHIGH, GDT_TYPE_DATAorCODE_W_WRITABLE, GDT_TYPE_DATAorCODE_A), GDT_S_DATAorCODE, GDT_DPL_ring0, GDT_P_REAL, 0xF, GDT_AVL, GDT_L_0, GDT_DB_32, GDT_G_4KB, 0x0
    newGDT_DATAorCODE GDT_start, SelectorCode16, 0xFFFF, 0x0, 0x0, GDT_TYPE_DATAorCODE(GDT_TYPE_DATAorCODE_X_CODE, GDT_TYPE_DATAorCODE_C_1, GDT_TYPE_DATAorCODE_R_READABLE, GDT_TYPE_DATAorCODE_A), GDT_S_DATAorCODE, GDT_DPL_ring0, GDT_P_REAL, 0xF, GDT_AVL, GDT_L_0, GDT_DB_16, GDT_G_4KB, 0x0
    newGDT_DATAorCODE GDT_start, SelectorData16, 0xFFFF, 0x0, 0x0, GDT_TYPE_DATAorCODE(GDT_TYPE_DATAorCODE_X_DATA, GDT_TYPE_DATAorCODE_E_TOHIGH, GDT_TYPE_DATAorCODE_W_WRITABLE, GDT_TYPE_DATAorCODE_A), GDT_S_DATAorCODE, GDT_DPL_ring0, GDT_P_REAL, 0xF, GDT_AVL, GDT_L_0, GDT_DB_16, GDT_G_4KB, 0x0
    newGDT_DATAorCODE GDT_NULL
    newGDT_DATAorCODE GDT_NULL

GDT_end:

GDT_PTR:
    dw GDT_end - GDT_start - 1
    dd 0x5000

