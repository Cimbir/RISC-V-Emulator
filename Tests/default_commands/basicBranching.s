.text
main:

addi sp, sp, -32

# int i;
addi sp, sp, -4

# i = 10;
li x10, 10
sw x10, 0(sp)

# if(i >= 0){ i += 10 }
# i *= 10 

# if(i >= 0) 
lw x10, 0(sp)
blt x10, x0, if_true
# i += 10
lw x10, 0(sp)
addi x10, x10, 10
sw x10, 0(sp)

if_true:
# i *= 10
lw x10, 0(sp)
li x11, 10
mul x10, x10, x11
sw x10, 0(sp)

# save result
lw x11, 0(sp)

# destroy i
addi sp, sp, 4

addi sp, sp, 32

li x10, 1
ecall
li x10, 10
ecall