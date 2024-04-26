# main(){
#   short arr[4];
#   arr[0] = 3;
#   arr[3] = 15;
# }

.text
main:

# grow for vars
addi sp, sp, -8

li x10, 0 # index = 0
li x11, 3 # val = 3
slli x10, x10, 1 # index * 2 bytes
add x10, sp, x10 # address of arr[0]
sh x11, 0(x10) # arr[0] = 3

li x10, 3
li x11, 15
slli x10, x10, 1
add x10, sp, x10
sh x11, 0(x10)

li x12, 0
li x13, 4
while_head:
bge x12, x13, while_done
slli x10, x12, 1
add x10, sp, x10
lh x11, 0(x10)
li x10, 1
ecall
addi x12, x12, 1
j while_head

while_done:

# shrink for vars
addi sp, sp, 8

# exit
li x10, 10
ecall