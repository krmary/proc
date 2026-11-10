in AX
in BX
in CX ; jvllv
push 0
push AX
jne 14
call :1
push BX
push BX
mul
push -4
push AX
mul
push CX
mul
add
pop DX
push DX
push 0
jne 38
call :2
push DX
push 0
jb 48
push -666
out
hlt
push DX
push 2
sqrt
pop DX
push -1
push BX
mul
push DX
add
push 2
push AX
mul
div
out
push -1
push BX
mul
push DX
sub
push 2
push AX
mul
div
out
hlt
:1
push -1
push CX
mul
push BX
div
out
hlt
:2
push -1
push BX
mul
push 2
push AX
mul
div
out
hlt
