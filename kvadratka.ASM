in AX
in BX
in CX
push 0
push AX
jne 24
push 0; print 39
push BX
jne 22
push -666
out
hlt
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
jne 48
call :2
push DX
push 0
jb 58
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
