.text
main:
# grow stack
addi sp, sp, -32

# int i = 6;
# make space for i
addi sp, sp, -4
# i = 6
li x10, 6
sw x10, 0(sp)

# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)

# save result somewhere else
lw x11, 0(sp)

# we no longer need i
addi sp, sp, 4

# shrink stack
addi sp, sp, 32

# output i
# prints x11 in the format x10
li x10, 1
ecall

# exit(), exit=10
li x10, 10
ecall

tmp: