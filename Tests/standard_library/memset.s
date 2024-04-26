addi sp, sp, -32

li x10, 10
li x11, 66
memset 0(sp), x11, x10

printf 0(sp)

addi sp, sp, 32