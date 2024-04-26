addi sp, sp, -32

li x10, 10
malloc x15, x10
li x10, 25
malloc x16, x10

li x10, 10
li x11, 67
memset 0(x15), x11, x10 
li x10, 1
mv x11, x15
ecall

li x10, 20
realloc x15, x15, x10

printf 0(x15)
li x10, 1
mv x11, x15
ecall

free x15

addi sp, sp, 32