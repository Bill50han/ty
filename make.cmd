echo off
@set path=%cd%\bin\;%path%
call "D:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw-w64.bat"
echo on


::编译

::hal
nasm -i.\source\include\ -fbin .\source\hal\hal.asm -o .\tmp\hal

::tyldr
nasm -i.\source\include\ -fbin .\source\tyldr\head.asm -o .\tmp\head

::tyoskrnl
nasm -felf64 .\source\kernel\tyosbase.asm -o .\tmp\tyosmain.asm.o
gcc -mcmodel=large  -fno-builtin  -nostdlib -m64 -c .\source\kernel\tyosbase.c -o .\tmp\tyosmain.c.o 

::---------------------------------------------------------------------------------------------------------------

::"链接"
cd .\tmp\

::hal

::tyldr
ren .\head tyldr

::tyoskrnl
ld -T ..\config\link.lds -o tyosmain.o tyosmain.asm.o tyosmain.c.o 
objcopy -R .comment -R .note -S -O binary tyosmain.o tyoskrnl

::生成
cd ..
copy .\tmp\tyldr .\release\
copy .\tmp\hal .\release\
copy .\tmp\tyoskrnl .\release\
del .\tmp\tyoskrnl
del .\tmp\tyldr
del .\tmp\hal

pause
