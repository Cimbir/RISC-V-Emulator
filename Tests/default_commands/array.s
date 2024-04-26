.text
main:

addi sp, sp, -128

# int i = 3;
# int arr[10];
# arr[i]= 7;

# int i, int arr[10];
addi sp, sp, -44

# i = 3
li x10, 3
sw x10, 40(sp)

# load i in x10
lw x10, 40(sp)
# get real offset by *4 aka <<2
slli x10, x10, 2
# get address of arr[i]
add x10, sp, x10

# arr[i] = 7
li x11, 7
sw x11, 0(x10)



# for printing out result
li x13 0
li x14 10
while_loop:
bge x13, x14, while_done

slli x15, x13, 2
add x15, sp, x15
lw x11, 0(x15)
li x10, 1
ecall

addi x13, x13, 1
j while_loop

while_done:



addi sp, sp, 44

addi sp, sp, 128

li x10, 10
ecall