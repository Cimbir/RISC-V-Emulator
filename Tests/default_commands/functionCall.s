.text
main:

# grow stack
addi sp, sp, -8

li x10, 12
sw x10, 0(sp) # arg0 = 10
li x10, 13
sw x10, 4(sp) # arg1 = 13
# add(arg0,arg1)
call add

# shrink stack
addi sp, sp, 8

# exit
li x10, 10
ecall

add:
lw x11, 0(sp) # res = arg0
lw x12, 4(sp) # tmp = arg1
add x11, x11, x12 # res = res + tmp
li x10, 1
ecall

ret