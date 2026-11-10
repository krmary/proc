in BX
in CX
in DX
push 0
pop AX
push AX
push AX
push 26
div
push 26
mul
sub
push BX
sub
push 2
pow
push AX
push 26
div
push CX
sub
push 2
pow
push 4
mul
add
push DX
push 2
pow
sub
push DX
push 4
div
sub
push 0
jb 62
push 1
pop [AX]
push AX
push 1
add
pop AX
push 338
push AX
jb 10
printm
hlt
