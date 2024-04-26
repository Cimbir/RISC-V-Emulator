.text
main:

addi sp, sp, -32

# char ch = 'A'
# make space for char
addi sp, sp, -1

# ch = 'A'
li x10, 65
sw x10, 0(sp)

lw x11, 0(sp)

# clear space for ch
addi sp, sp, 1

addi sp, sp, 32

li x10, 11
ecall
li x10, 10
ecall