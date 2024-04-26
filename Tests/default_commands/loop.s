.text
main:

addi sp, sp, -32

# int a = 10;
# for(int i = 0; i < 10; i++){
#   a += 2;
# }
#
# is the same as
#
# while(i < 10){
#   a += 2;
#   i++;
# }

# int a, int i;
addi sp, sp, -8

# a = 10;
li x10, 10
sw x10, 4(sp)

# i = 0;
sw x0, 0(sp)

# (i >= 10) => jump to while_done
# if not, continue with while_body
while_head:
lw x10, 0(sp)
li x11, 20
bge x10, x11, while_done
# a += 2
lw x11, 4(sp)
addi x11, x11, 2
sw x11, 4(sp)
# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)
j while_head

while_done:
lw x11, 4(sp)

# destroy a and i
addi sp, sp, 8

addi sp, sp, 32

li x10, 1
ecall
li x10, 10
ecall