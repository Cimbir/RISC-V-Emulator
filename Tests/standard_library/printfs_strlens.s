addi sp, sp, -32

li x10, 66
sw x10, 0(sp)
li x10, 67
sw x10, 1(sp)
li x10, 68
sw x10, 2(sp)
li x10, 69
sw x10, 3(sp)

printfs 0(sp)
strlens x11, 0(sp)

li x10, 1
ecall

addi sp, sp, 32