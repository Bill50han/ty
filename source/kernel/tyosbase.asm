;jmp start
;%macro string 2
;%1:
;db %2
;%1_end:
;%endmacro
;
;%define strlen(s) (s %+ _end - s)
;
;
;string hello,'hello'
;
;
;start:
;mov ax, 0
;
;mov cx, strlen(hello)
;mov si, hello
;call newline
;call printstr
;cli
;hlt
;
;printstr: ;显示指定的字符串, cx中的strlen结果代表字符数量
;mov al,[si] 
;mov ah,0eh 
;int 10h 
;inc si 
;loop printstr
;ret
;
;newline: ;显示回车换行 
;mov ah,0eh 
;mov al,0dh 
;int 10h 
;mov al,0ah 
;int 10h 
;ret
;
global _start
extern test

_start:
call test

end:
hlt
jmp end

IA32Mode2RealMode:
