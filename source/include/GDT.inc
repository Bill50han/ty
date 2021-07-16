%macro newGDT_DATAorCODE 15
%if %1 == 0
dq 0
%else
GDT_%2_start:
dw %3
dw %4
db %5
db ( %9 << 7 ) + ( %8 << 6 ) + ( %7 << 4 ) + %6
db ( %14 << 7 ) + ( %13 << 6 ) + ( %12 << 5 ) + ( %11 << 4 ) + %10
db %15
%2 equ GDT_%2_start - %1
%endif
%endmacro

%macro newGDT_64_CALLGATE 7
dw %1
dw %2
dw ( %4 << 15 ) + ( %3 << 13 ) + ( 1100b << 8 )
dw %5
dd %6
db 0
db %7
dw 0
%endmacro

%macro newGDT_64_IDT 7
dw %1
dw %2
db %3
db ( %5 << 7 ) + ( %4 << 5 ) + 1110b
dw %6
dd %7
dd 0
%endmacro

%macro newGDT_64_TSS 7

%endmacro

%define GDT_NULL 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

%define GDT_TYPE_DATAorCODE(X, CE, RW, A) X %+ CE %+ RW %+ A %+ b

%define GDT_TYPE_DATAorCODE_X_CODE 1
%define GDT_TYPE_DATAorCODE_X_DATA 0
%define GDT_TYPE_DATAorCODE_C_0 0
%define GDT_TYPE_DATAorCODE_C_1 1
%define GDT_TYPE_DATAorCODE_E_TOHIGH 0
%define GDT_TYPE_DATAorCODE_E_TOLOW 1
%define GDT_TYPE_DATAorCODE_R_READABLE 1
%define GDT_TYPE_DATAorCODE_R_UNREADABLE 0
%define GDT_TYPE_DATAorCODE_W_WRITABLE 1
%define GDT_TYPE_DATAorCODE_W_UNWRITABLE 0
%define GDT_TYPE_DATAorCODE_A 0

%define GDT_TYPE_SYS_32_16_TSS_AVL 0001b
%define GDT_TYPE_SYS_32_LDT 0010b
%define GDT_TYPE_SYS_32_16_TSS_BUSY 0011b
%define GDT_TYPE_SYS_32_16_CALLGATE 0100b
%define GDT_TYPE_SYS_32_TASKGATE 0101b
%define GDT_TYPE_SYS_32_16_INTGATE 0110b
%define GDT_TYPE_SYS_32_16_TRAPGATE 0111b
%define GDT_TYPE_SYS_32_TSS_AVL 1001b
%define GDT_TYPE_SYS_32_TSS_BUSY 1011b
%define GDT_TYPE_SYS_32_CALLGATE 1100b
%define GDT_TYPE_SYS_32_INTGATE 1110b
%define GDT_TYPE_SYS_32_TRAPGATE 1111b

%define GDT_TYPE_SYS_64_LDT 0010b
%define GDT_TYPE_SYS_64_TSS_AVL 1001b
%define GDT_TYPE_SYS_64_TSS_BUSY 1011b
%define GDT_TYPE_SYS_64_CALLGATE 1100b
%define GDT_TYPE_SYS_64_INTGATE 1110b
%define GDT_TYPE_SYS_64_TRAPGATE 1111b

%define GDT_S_SYS 0
%define GDT_S_DATAorCODE 1

%define GDT_DPL_ring0 0
%define GDT_DPL_ring3 3

%define GDT_P_REAL 1
%define GDT_P_VIRTUAL 0

%define GDT_AVL 0

%define GDT_L_64 1
%define GDT_L_0 0

%define GDT_DB_32 1
%define GDT_DB_16 0

%define GDT_G_1B 0
%define GDT_G_4KB 1