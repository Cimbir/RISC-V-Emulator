# int main(){
#     int a = 5;
#     for(int i = 0; i < 10; i++){
#         a++;
#     }
#     printf("%d",a);

#     return 0;
# }
.text
main:

addi sp, sp, -8

# a = 5;
li x10, 5
sw x10, 4(sp)
# i = 0;
li x10, 0
sw x10, 0(sp)

for_head:
lw x10, 0(sp)
li x11, 10
bge x10, x11, for_end # (i >= 10) end

# a++
lw x10, 4(sp)
addi x10, x10, 1
sw x10, 4(sp)

# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)
j for_head

for_end:

lw x11, 4(sp)
li x10, 1
ecall

addi sp, sp, 8

li x10, 10
ecall