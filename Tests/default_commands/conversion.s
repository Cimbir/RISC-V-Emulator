.text
main:

# int i = 5;
# char c = i;

# int i, char c
addi sp, sp, -5

# i = 5;
li x10, 65
sw x10, 1(sp)

# c = i;
lb x10, 1(sp)
sb x10, 0(sp)

# save res
lb x11, 0(sp)

# reset stack
addi sp, sp, 5

li x10 11
ecall
li x10 10
ecall