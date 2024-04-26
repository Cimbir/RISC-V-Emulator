# struct pet{
#     short age;
#     int weight;
# }
# void petpet(pet* a){
#     a->age = 10 * a->age
#     a->weight = 7 * a->weight;
# }
# int main(){
#     pet t;
#     t.age = 3;
#     t.weight = 4;
#     petpet(&t);
#     printf("%d%d",t.age,t.weight);
#     return 0;
# }

.text
main:

# pet t;
addi sp, sp, -6

# t.age = 3;
li x10, 3
sh x10, 0(sp)

# t.weight = 4;
li x10, 4
sw x10, 2(sp)

# petpet(&t);
addi sp, sp, -4

addi x10, sp, 4
sw x10, 0(sp)

call petpet

addi sp, sp, 4

# printf("%d%d",t.age,t.weight);
lh x11, 0(sp)
li x10, 1
ecall
lw x11, 2(sp)
li x10, 1
ecall

addi sp, sp, 6

li x10, 10
ecall

petpet:

addi sp, sp, -4
sw ra, 0(sp)

lw x12, 4(sp)

# a->age = 10 * a->age
lh x10, 0(x12)
li x11, 10
mul x10, x10, x11
sh x10, 0(x12)  

# a->weight = 7 * a->weight;
lw x10, 2(x12)
li x11, 7
mul x10, x10, x11
sw x10, 2(x12)

lw ra, 0(sp)
addi sp, sp, 4

ret