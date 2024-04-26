# main(){
#     int i = 10;
#     step(i);
#     return 0;
# }
# void step(int i){
#     printf("%d",i);
#     if(i == 1) return;
#     else if(i % 2 == 0) step(i/2);
#     else if(i % 2 == 1) step(3*i+1);
# }

.text
main:

addi sp, sp, -4

# int i = 10;
li x10, 100
sw x10, 0(sp)

addi sp, sp, -4
lw x10, 4(sp)
sw x10, 0(sp)
call step
addi sp, sp 4

addi sp, sp, 4

li x10, 10
ecall

step:
addi sp, sp, -4
sw ra, 0(sp)

# printf("%d",i);
lw x11, 4(sp)
li x10, 1
ecall

# int i - 4(sp)

# if(i == 1)
li x12, 1
lw x11, 4(sp) # i
beq x12, x11, done

# else if(i % 2 == 0)
li x12, 1
lw x11, 4(sp) # i
and x13, x11, x12 # i % 2 = x13
beq x12, x13, is_odd

# step(i/2);
lw x11, 4(sp) # i
srli x11, x11, 1 # i/2

addi sp, sp, -4
sw x11, 0(sp)
call step
addi sp, sp, 4

lw ra, 0(sp)
addi sp, sp, 4
ret
# i/2

is_odd:

# step(3*i+1);
lw x11, 4(sp) # i
li x12, 3
mul x11, x11, x12 # 3*i
addi x11, x11, 1 # 3*i+1

addi sp, sp, -4
sw x11, 0(sp)
call step
addi sp, sp, 4

lw ra, 0(sp)
addi sp, sp, 4
ret
# 3*i+1

done:
# i = 1
lw ra, 0(sp)
addi sp, sp, 4
ret
# 1