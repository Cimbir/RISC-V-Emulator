.text 
main:

addi sp,sp,-8 #for arguments
li x11,12 
li x12,13

sw x11,0(sp) # store 12 in stack
sw x12,4(sp) # store 13 in stack

call f
addi sp,sp,8

li x10,10
ecall

f:

lw x10,0(sp) # load int a 
lw x11,4(sp) # load int b

addi sp,sp,-12 #for locals and ra 
sw ra,8(sp)

add x10,x10,x11 # a+b
sw x10,4(sp) # x = a+b

lw x10,4(sp)
mul x11,x10,x10 # x*x
sw x11,0(sp) # y = x*x

lw ra, 8(sp)

addi sp,sp,12
ret