# int main(){
#     int nums[10];
#     for(int i = 0; i < 10; i++){
#         nums[i] = i * 2;
#         printf("%d",nums[i]);
#     }
#     return 0;
# }
.text
main:

# int nums[10], int i;
addi sp, sp, -44

# i = 0;
li x10, 0
sw x10, 0(sp)

for_head:
lw x10, 0(sp) # i
li x11, 10
bge x10, x11, for_end # (i >= 10) -> end

# nums[i] = i * 2
addi x11, sp, 4
slli x12, x10, 2
add x11, x11, x12 # nums[i] ptr
slli x12, x10, 1 # i * 2
sw x12, 0(x11) # nums[i] = i * 2;

# printf("%d",nums[i]);
addi x11, sp, 4
slli x12, x10, 2
add x11, x11, x12 # nums[i] ptr
lw x11, 0(x11)
li x10, 1
ecall

# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)

j for_head

for_end:

addi sp, sp, 44

li x10, 10
ecall