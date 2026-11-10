in AX
push AX
push 0
jb 10
jmp :2
push 1
pop BX
push 1
call :1
out
hlt
:1
push BX
push 1
add
pop BX
push BX
mul
push BX
push AX
je 18
call :1
ret
:2
push 0
push AX
jne 49
push 1
out
hlt
push 0
out
hlt
