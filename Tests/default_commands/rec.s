# int sm(int a){
#     if(a == 1) return a;
#     return a + sm(a-1);
# }
# int main(){
#     int a = 5;
#     int m = sm(a);
#     printf("%d",m);
#     return 0;
# }
.text
main:
addi sp, sp, -8

# a = 5
li x10, 7
sw x10, 4(sp)

addi sp, sp, -4

lw x10, 8(sp)
sw x10, 0(sp)
call sm
sw x11, 4(sp)

addi sp, sp, 4

# print
li x10, 1
lw x11, 0(sp)
ecall

addi sp, sp, 8

li x10, 10
ecall

sm:

addi sp, sp, -4
sw ra, 0(sp)

lw x12, 4(sp)
li x13, 1
beq x12, x13, is_eq
addi sp, sp, -4

lw x12, 8(sp)
addi x12, x12, -1
sw x12, 0(sp)
call sm

addi sp, sp, 4

lw x12, 4(sp)
add x11, x12, x11

lw ra, 0(sp)
addi sp, sp, 4
ret

is_eq:
li x11, 1

lw ra, 0(sp)
addi sp, sp, 4
ret