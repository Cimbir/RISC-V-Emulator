# int i = 1025;
# char ch = i;

.text
main:

addi sp, sp, -32

# int i, char ch;
addi sp, sp, -5

# i = 1025;
li x10, 1025
sw x10, 1(sp)

# ch = i;
lb x10, 1(sp)
sb x10, 0(sp)

lb x11, 0(sp)

addi sp, sp, 5

addi sp, sp, 32

li x10, 1
ecall
li x10, 10
ecall