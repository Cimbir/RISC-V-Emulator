# main(){
#     int i = 4;
#     printf(fact(i));
#     return 0;
# }
# int fact(int i){
#     if(i == 0) return 0;
#     return i * fact(i-1);
# }

.text
main:
addi sp, sp, -4

li x10, 10
sw x10, 0(sp) # i = 4;

addi sp, sp, -4
lw x10, 4(sp)
sw x10, 0(sp) # arg1
call fact
addi sp, sp, 4

mv x11, x10
li x10, 1
ecall

addi sp, sp, 4
li x10, 10
ecall



fact:
addi sp, sp, -4
sw ra, 0(sp)

lw x10, 4(sp) # i

beq x10, x0, fact_end

addi x12, x10, -1 # i--

addi sp, sp, -4
sw x12, 0(sp)
call fact
addi sp, sp 4
# x10 - fact(i-1)

lw x11, 4(sp)
mul x10, x10, x11

lw ra, 0(sp)
addi sp, sp, 4
ret

fact_end:
li x10, 1

lw ra, 0(sp)
addi sp, sp, 4
ret