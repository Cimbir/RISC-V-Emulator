.text
main:
addi sp, sp, -8
li x10, 12
sw x10, 0(sp)
li x10, 13
sw x10, 4(sp)
call f
addi sp, sp, 8

mv x11, x10
li x10, 1
ecall
li x10, 10
ecall

f:
addi sp, sp, -12
sw ra, 8(sp)
# int x = a+b;
lw x10, 12(sp) # a
lw x11, 16(sp) # b
add x10, x10, x11 # a+b
sw x10, 4(sp) # x = a+b

# int y = x*x;
lw x10, 4(sp) # x
mul x10, x10, x10 # x*x
sw x10, 0(sp) # y = x*x

# return y;
lw x10, 0(sp)

lw ra, 8(sp)
addi sp, sp, 12
ret