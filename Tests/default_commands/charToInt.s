# char ch = 'A';
# int i = ch;

.text
main:

addi sp, sp, -32

# char ch, int i;
addi sp, sp, -5

# ch = 'A';
li x10, 65
sb x10, 4(sp)

# i = ch;
lb x10, 4(sp)
sw x10, 0(sp)

# save for output
lb x11, 4(sp)
lw x12, 0(sp)

# clear 
addi sp, sp, 5

addi sp, sp, 32

li x10, 11
ecall
addi x11, x12, 0
li x10, 1
ecall
li x10, 10
ecall