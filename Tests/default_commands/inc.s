.text
main:

# int i = 10;
# printf("%d",i);
# i++;
# printf("%d",i);

addi sp, sp, -4

# int i = 10;
li x10, 10
sw x10, 0(sp)

# printf("%d",i);
lw x11, 0(sp)
li x10, 1
ecall

# i++;
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)

# printf("%d",i);
lw x11, 0(sp)
li x10, 1
ecall

addi sp, sp, 4

# exit
li x10, 10
ecall