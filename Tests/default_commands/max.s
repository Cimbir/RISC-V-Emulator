# int max(int a, int b){
#     if(a < b){
#         return a;
#     }else{
#         return b;
#     }
# }
# int main(){
#     int a = 5;
#     int b = 10;
#     printf("%d",max(a,b));
#     return 0;
# }
.text
main:

addi sp, sp, -8

# int a = 5;
li x10, 25
sw x10, 4(sp)

# int b = 10;
li x10, 100
sw x10, 0(sp)

# printf("%d",max(a,b));
addi sp, sp, -8

lw x10, 12(sp)
sw x10, 0(sp)
lw x10, 8(sp)
sw x10, 4(sp)
call max

addi sp, sp, 8

li x10 1
ecall

addi sp, sp, 8

li x10, 10
ecall

max:

addi sp, sp, -4
sw ra, 0(sp)

# if(a < b)
lw x12, 4(sp) # a
lw x13, 8(sp) # b
blt x12, x13, b_more
mv x13, x12

b_more:
mv x11, x13

lw ra, 0(sp)
addi sp, sp, 4
ret