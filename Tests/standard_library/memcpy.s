addi sp, sp, -32

li x10, 66
sb x10, 0(sp)
li x10, 67
sb x10, 1(sp)
li x10, 68
sb x10, 2(sp)
li x10, 0
sb x10, 3(sp)
mv x12, sp

addi sp, sp, -100

li x10, 4
memcpy 0(sp), 0(x12), x10

printf 0(sp)

addi sp, sp, 32