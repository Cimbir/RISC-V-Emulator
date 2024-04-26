# main(){
#     int a = 0;
#     int b = 1;
#     int c = 1;

#     for(int i = 0; i < 10; i++){
#         printf("%d",a);
#         a = b;
#         b = c;
#         c = a + b;
#     }

#     return 0;
# }

.text
main:
addi sp, sp, -16

li x10, 0
sw x10, 12(sp) # a
li x10, 1
sw x10, 8(sp) # b
li x10, 1
sw x10, 4(sp) # c
li x10, 0
sw x10, 0(sp) # i

# while(i < 4)
while_head:
lw x10, 0(sp) # i
li x11, 10
bge x10, x11, while_end

# printf("%d",a);
lw x11, 12(sp)
li x10, 1
ecall
# for whitespace
li x11, 32
li x10, 11
ecall

# a = b;
lw x10, 8(sp)
sw x10, 12(sp)
# b = c;
lw x10, 4(sp)
sw x10, 8(sp)
# c = a+b;
lw x10, 12(sp)
lw x11, 8(sp)
add x10, x10, x11
sw x10, 4(sp)

# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)
j while_head

while_end:
addi sp, sp, 16
li x10, 10
ecall