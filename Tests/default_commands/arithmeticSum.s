# main(){
#     int n = 4;
#     int a = 10;
#     int d = 3;

#     printf(arSum(n,a,d));

#     return 0;
# }
# int arSum(int n, int a, int d){
#     if(n == 1) return a;
#     return a + arSum(n-1,a+d,d);
# }

.text
main:
addi sp, sp, -12

li x10, 4
sw x10, 8(sp)
li x10, 10
sw x10, 4(sp)
li x10, 3
sw x10, 0(sp)

# arSum(n,a,d)
addi sp, sp, -12
lw x10, 20(sp)
sw x10, 0(sp)
lw x10, 16(sp)
sw x10, 4(sp)
lw x10, 12(sp)
sw x10, 8(sp)
call arSum
addi sp, sp, 12
# res in x10

# printf(res)
mv x11, x10
li x10, 1
ecall

addi sp, sp, 12

li x10, 10
ecall



arSum:
addi sp, sp, -4
sw ra, 0(sp)

# if(n == 1) return a;
lw x11, 4(sp) # n
li x12, 1
beq x11, x12, sum_end

# arSum(n-1,a+d,d);
addi sp, sp, -12
lw x11, 16(sp) # n
addi x11, x11, -1 # n-1
sw x11, 0(sp)
lw x11, 20(sp) # a
lw x12, 24(sp) # d
add x11, x11, x12 # a = a + d
sw x11, 4(sp)
sw x12, 8(sp)
call arSum
addi sp, sp, 12

lw x11, 8(sp)
add x10, x10, x11 

lw ra, 0(sp)
addi sp, sp, 4
ret

sum_end:
lw x10, 8(sp)

lw ra, 0(sp)
addi sp, sp, 4
ret